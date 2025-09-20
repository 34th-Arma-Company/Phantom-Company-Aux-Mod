/*
	Author: 34th PC Modding Team
	Decide if a civilian surrenders, flees, or resists when approached.
*/

params ["_civ", "_arrester", ["_weights", [0.55, 0.30, 0.15]], ["_opts", []]];
if (isNull _civ || {isNull _arrester} || {!alive _civ}) exitWith {};
if (_civ getVariable ["pc_cs_decided", false]) exitWith {};

private _optMap = createHashMapFromArray _opts;
private _debug = _optMap getOrDefault ["debug", false];
private _fleeRadius = _optMap getOrDefault ["fleeRadius", 80];
private _changeSideOnResist = _optMap getOrDefault ["changeSideOnResist", true];
private _autoSurrenderACE = _optMap getOrDefault ["autoSurrenderACE", true];
private _forceFirstShot = _optMap getOrDefault ["forceFirstShot", true];
private _boostSkills = _optMap getOrDefault ["boostSkills", true];
private _noPathingResist = _optMap getOrDefault ["noPathingWhenResist", true];
private _fastDrawCoef = _optMap getOrDefault ["fastDrawCoef", 1.6];
private _fastDrawDuration = _optMap getOrDefault ["fastDrawDuration", 1.0];
private _useInstantPose = _optMap getOrDefault ["useInstantPose", true];

_civ setVariable ["pc_cs_decided", true, true];

private _defaultLoads = [
	["hgun_P07_F", "16Rnd_9x21_Mag", 3],
	["hgun_Rook40_F", "16Rnd_9x21_Mag", 3],
	["hgun_ACPC2_F", "9Rnd_45ACP_Mag", 3]
];
private _armedLoadsRaw = _optMap getOrDefault ["armedLoadouts", _defaultLoads];
private _pickLoadout = {
	params ["_raw"];
	if ((count _raw) > 0 && {typeName (_raw # 0) == "ARRAY"}) exitWith {selectRandom _raw};
	_raw
};
private _armedLoadout = [_armedLoadsRaw] call _pickLoadout;

if (_debug) then {
	diag_log format [
		"[PCAUX][decide] START civ:%1 owner:%2 local:%3 arrester:%4 side:%5",
		_civ,
		owner _civ,
		local _civ,
		name _arrester,
		side (group _arrester)
	];
};

private _ws = +_weights;
if ((count _ws) != 3) then {_ws = [0.55, 0.30, 0.15];};
private _sum = (_ws # 0) + (_ws # 1) + (_ws # 2);
if (_sum <= 0) then {
	_ws = [0.55, 0.30, 0.15];
	_sum = 1;
};
_ws = [(_ws # 0) / _sum, (_ws # 1) / _sum, (_ws # 2) / _sum];

_civ enableAI "MOVE";
_civ enableAI "AUTOTARGET";
_civ setCaptive false;

private _awayDir = (_civ getDir _arrester) + 180;
private _awayPos = [_civ, _fleeRadius, _awayDir] call BIS_fnc_relPos;

private _r = random 1;

if (_r <= _ws # 0) exitWith {
	private _hasACE = isClass (configFile >> "CfgPatches" >> "ace_captives");
	if (_hasACE && _autoSurrenderACE) then {
		[_civ, true] call ace_captives_fnc_setSurrendered;
	} else {
		_civ disableAI "MOVE";
		_civ disableAI "AUTOTARGET";
		_civ setUnitPos "UP";
		_civ switchMove "AmovPercMstpSsurWnonDnon";
	};
	if (_debug) then {diag_log format ["[PCAUX][decide] %1 -> SURRENDER", _civ];};
};

if (_r <= (_ws # 0 + _ws # 1)) exitWith {
	_civ allowFleeing 1;
	_civ setBehaviour "AWARE";
	_civ setSpeedMode "FULL";
	_civ doMove _awayPos;
	[_civ, _awayPos] spawn {
		params ["_u", "_pos"];
		for "_i" from 1 to 10 do {
			if (!alive _u) exitWith {};
			_u doMove _pos;
			sleep 1.2;
		};
	};
	if (_debug) then {diag_log format ["[PCAUX][decide] %1 -> FLEE to %2", _civ, _awayPos];};
};

if (_changeSideOnResist) then {
	private _grp = createGroup [east, true];
	[_civ] joinSilent _grp;
};

private _wep = _armedLoadout param [0, "hgun_P07_F", [""]];
private _mag = _armedLoadout param [1, "16Rnd_9x21_Mag", [""]];
private _cnt = _armedLoadout param [2, 3, [0]];
_cnt = _cnt max 1;

removeAllWeapons _civ;
_civ addMagazines [_mag, _cnt + 1];
_civ addWeapon _wep;
_civ selectWeapon _wep;
reload _civ;

if (_boostSkills) then {
	_civ setSkill ["courage", 1];
	_civ setSkill ["aimingSpeed", 0.8];
	_civ setSkill ["spotTime", 0.1];
	_civ setSkill ["spotDistance", 0.8];
};
if (_useInstantPose) then {_civ switchMove "AmovPercMstpSrasWpstDnon";};
if (_fastDrawCoef > 1) then {
	_civ setAnimSpeedCoef _fastDrawCoef;
	[_civ, _fastDrawDuration] spawn {
		params ["_u", "_dur"];
		uiSleep _dur;
		if (alive _u) then {_u setAnimSpeedCoef 1;};
	};
};

if (_noPathingResist) then {
	_civ disableAI "PATH";
	_civ forceSpeed -1;
};

_civ allowFleeing 0;
_civ setBehaviour "COMBAT";
_civ setCombatMode "RED";
_civ setSpeedMode "FULL";
_civ doWatch _arrester;
_civ reveal [_arrester, 4];
_civ doTarget _arrester;
_civ doFire _arrester;
_civ setUnitPos "UP";

if (_forceFirstShot) then {
	[_civ] spawn {
		params ["_u"];
		uiSleep 0.1;
		private _muzzle = currentMuzzle _u;
		private _mode = currentWeaponMode _u;
		if (!isNil "_muzzle" && {!isNil "_mode"}) then {
			_u forceWeaponFire [_muzzle, _mode];
		};
	};
};

[_civ, _arrester, _noPathingResist] spawn {
	params ["_u", "_p", "_pathOff"];
	for "_i" from 1 to 6 do {
		if (!alive _u || {!alive _p}) exitWith {};
		_u doWatch _p;
		_u doTarget _p;
		_u doFire _p;
		if (!_pathOff) then {
			_u doMove (getPosATL _p);
		};
		sleep 0.4;
	};
};

if (_debug) then {diag_log format ["[PCAUX][decide] %1 -> RESIST-ARMED", _civ];};

