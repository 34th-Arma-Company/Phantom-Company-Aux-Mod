/*
	Author: 34th PC Modding Team
	Creates and manages the player proximity trigger for a civilian.
*/

params ["_civ", "_sidesThatTrigger", "_radius", "_weights", "_opts"];
if (isNull _civ || {!alive _civ}) exitWith {};

_civ setVariable ["pc_cs_watchStarted", true, true];

private _optMap = createHashMapFromArray _opts;
private _debug = _optMap getOrDefault ["debug", false];

if (_debug) then {
	diag_log format ["[PCAUX][attach] start for %1 (owner %2) r=%3 sides=%4", _civ, owner _civ, _radius, _sidesThatTrigger];
};

private _trg = createTrigger ["EmptyDetector", getPosWorld _civ, false];
_trg setTriggerArea [_radius, _radius, 0, false];
_trg setTriggerActivation ["ANYPLAYER", "PRESENT", true];
_trg setVariable ["pc_cs_civ", _civ];
_trg setVariable ["pc_cs_sides", _sidesThatTrigger];
_trg setVariable ["pc_cs_radius", _radius];
_trg setVariable ["pc_cs_weights", _weights];
_trg setVariable ["pc_cs_opts", _opts];
_trg setVariable ["pc_cs_done", false];

[_trg] spawn {
	params ["_t"];
	while {!isNull _t && {!(_t getVariable ["pc_cs_done", false])}} do {
		private _c = _t getVariable ["pc_cs_civ", objNull];
		if (isNull _c || {!alive _c}) exitWith {deleteVehicle _t;};
		_t setPosWorld (getPosWorld _c);
		uiSleep 0.05;
	};
};

private _cond = "this";
private _onAct =
" private _t = thisTrigger; \
  private _civ = _t getVariable [""pc_cs_civ"", objNull]; \
  if (isNull _civ) exitWith {}; \
  if (!alive _civ) exitWith {}; \
  if (_civ getVariable [""pc_cs_decided"", false]) exitWith {}; \
  private _sides = _t getVariable [""pc_cs_sides"", [west]]; \
  private _r = _t getVariable [""pc_cs_radius"", 1]; \
  private _weights = _t getVariable [""pc_cs_weights"", [0.55,0.3,0.15]]; \
  private _opts = _t getVariable [""pc_cs_opts"", []]; \
  private _near = allPlayers select {isPlayer _x && {side _x in _sides} && {(_x distance _civ) <= _r}}; \
  if ((count _near) > 0) then { \
    private _arrester = _near select 0; \
    [_civ, _arrester, _weights, _opts] call PCAUX_fnc_civSurrenderDecide; \
  }; \
  _t setVariable [""pc_cs_done"", true]; \
  deleteVehicle _t; \
";
private _onDea = "";

_trg setTriggerStatements [_cond, _onAct, _onDea];

if (_debug) then {
	diag_log format ["[PCAUX][attach] trigger created for %1 (local %2)", _civ, local _trg];
};
