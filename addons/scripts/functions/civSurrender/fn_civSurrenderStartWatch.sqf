/*
	Author: 34th PC Modding Team
	Attaches the proximity logic to a civilian while handling locality handoff.
*/

params ["_unit", "_sides", "_radius", "_weights", "_opts"];
if (isNull _unit || {!alive _unit}) exitWith {};
if (!(_unit isKindOf "CAManBase")) exitWith {};
if (_unit getVariable ["pc_cs_watchStarted", false]) exitWith {};

_unit setVariable ["pc_cs_watchStarted", true, true];

if (local _unit) then {
	[_unit, _sides, _radius, _weights, _opts] call PCAUX_fnc_civSurrenderAttachProximity;
} else {
	_unit addEventHandler [
		"Local",
		{
			params ["_u", "_local"];
			if (_local) then {
				[_u, _thisArgs # 0, _thisArgs # 1, _thisArgs # 2, _thisArgs # 3] call PCAUX_fnc_civSurrenderAttachProximity;
				_u removeEventHandler ["Local", _thisEventHandler];
			};
		},
		[_sides, _radius, _weights, _opts]
	];
};
