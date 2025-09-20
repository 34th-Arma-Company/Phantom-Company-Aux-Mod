/*
	Author: 34th PC Modding Team
	Eden module entry point for the civilian surrender system.
*/

params ["_logic", "_syncedUnits", "_activated"];
if (!_activated) exitWith {};
if (isNull _logic) exitWith {};
if (!local _logic) exitWith {};

private _debug = _logic getVariable ["PCAUX_CS_Debug", false];

private _sides = [];
if (_logic getVariable ["PCAUX_CS_SideWest", true]) then {_sides pushBack west;};
if (_logic getVariable ["PCAUX_CS_SideEast", false]) then {_sides pushBack east;};
if (_logic getVariable ["PCAUX_CS_SideResistance", false]) then {_sides pushBack resistance;};
if (_logic getVariable ["PCAUX_CS_SideCivilian", false]) then {_sides pushBack civilian;};
if (_sides isEqualTo []) then {_sides = [west];};

private _radius = _logic getVariable ["PCAUX_CS_Radius", 3];
_radius = (_radius max 0.5) min 500;

private _weights = [
	_logic getVariable ["PCAUX_CS_WeightSurrender", 0.55],
	_logic getVariable ["PCAUX_CS_WeightFlee", 0.30],
	_logic getVariable ["PCAUX_CS_WeightResist", 0.15]
];
_weights = _weights apply {(_x max 0) min 1};

private _fleeRadius = _logic getVariable ["PCAUX_CS_FleeRadius", 80];
_fleeRadius = (_fleeRadius max 1) min 1000;

private _opts = [
	["debug", _debug],
	["fleeRadius", _fleeRadius],
	["changeSideOnResist", _logic getVariable ["PCAUX_CS_ChangeSide", true]],
	["autoSurrenderACE", _logic getVariable ["PCAUX_CS_AutoSurrenderACE", true]],
	["boostSkills", _logic getVariable ["PCAUX_CS_BoostSkills", true]],
	["forceFirstShot", _logic getVariable ["PCAUX_CS_ForceFirstShot", true]],
	["noPathingWhenResist", _logic getVariable ["PCAUX_CS_NoPathing", true]],
	["fastDrawCoef", _logic getVariable ["PCAUX_CS_FastDrawCoef", 1.6]],
	["fastDrawDuration", _logic getVariable ["PCAUX_CS_FastDrawDuration", 1.0]],
	["useInstantPose", _logic getVariable ["PCAUX_CS_UseInstantPose", true]]
];

private _loadoutsRaw = _logic getVariable ["PCAUX_CS_ArmedLoadouts", []];
private _armedLoadouts = [];
if (_loadoutsRaw isEqualType "") then {
	if !(_loadoutsRaw isEqualTo "") then {
		private _compiled = call compile _loadoutsRaw;
		if (!isNil "_compiled" && {_compiled isEqualType []}) then {
			_armedLoadouts = _compiled;
		} else {
			if (_debug) then {
				diag_log format ["[PCAUX][module] armedLoadouts value could not be parsed: %1", _loadoutsRaw];
			};
		};
	};
} else {
	if (_loadoutsRaw isEqualType []) then {
		_armedLoadouts = _loadoutsRaw;
	};
};
if !(_armedLoadouts isEqualTo []) then {
	_opts pushBack ["armedLoadouts", _armedLoadouts];
};

private _targets = _syncedUnits select {
	alive _x && {_x isKindOf "CAManBase"} && {side (group _x) isEqualTo civilian}
};
if (_targets isEqualTo []) then {
	_targets = allUnits select {
		alive _x && {_x isKindOf "CAManBase"} && {side (group _x) isEqualTo civilian}
	};
};

{
	[_x, _sides, _radius, _weights, _opts] call PCAUX_fnc_civSurrenderStartWatch;
} forEach _targets;

if (_debug) then {
	diag_log format ["[PCAUX][module] attached surrender watch to %1 civilians.", count _targets];
};

true;

