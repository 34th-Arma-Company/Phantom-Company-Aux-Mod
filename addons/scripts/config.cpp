class CfgPatches
{
	class 34thPC_Scripts
	{
		author = "34th PC Modding Team";
		name = "Scripts";
		units[] = {"34thPC_Module_CivSurrender"};
		weapons[] = {};
		requiredAddons[] =
		{
			"A3_Modules_F",
			"A3_Functions_F"
		};
	};
};

class CfgFactionClasses
{
	class 34thPC_Modules
	{
		displayName = "34th PC Modules";
		priority = 2;
		side = 7;
	};
};

#include "cfgFunctions.hpp"

class CfgVehicles
{
	class Logic;
	class Module_F : Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;
			class Combo;
			class Checkbox;
			class CheckboxNumber;
			class List;
			class ListNBox;
		};
		class ModuleDescription;
	};

	class 34thPC_Module_CivSurrender : Module_F
	{
		author = "34th PC Modding Team";
		scope = 2;
		scopeCurator = 2;
		displayName = "Civilian Surrender System";
		category = "34thPC_Modules";
		function = "PCAUX_fnc_civSurrenderModuleInit";
		functionPriority = 1;
		isGlobal = 0;
		isTriggerActivated = 0;
		isDisposable = 0;
		curatorInfoType = "";
		icon = "\\a3\\Modules_F\\Data\\iconCivil_ca.paa";

		class Attributes : AttributesBase
		{
			class Debug : Checkbox
			{
				property = "PCAUX_CS_Debug";
				displayName = "Enable Debug Logging";
				tooltip = "Writes verbose surrender system diagnostics to the RPT.";
				expression = "_this setVariable ['PCAUX_CS_Debug', _value];";
				defaultValue = "false";
			};
			class SideWest : Checkbox
			{
				property = "PCAUX_CS_SideWest";
				displayName = "Allow BLUFOR to trigger";
				tooltip = "If enabled, BLUFOR players can trigger civilian reactions.";
				expression = "_this setVariable ['PCAUX_CS_SideWest', _value];";
				defaultValue = "true";
			};
			class SideEast : Checkbox
			{
				property = "PCAUX_CS_SideEast";
				displayName = "Allow OPFOR to trigger";
				tooltip = "If enabled, OPFOR players can trigger civilian reactions.";
				expression = "_this setVariable ['PCAUX_CS_SideEast', _value];";
				defaultValue = "false";
			};
			class SideResistance : Checkbox
			{
				property = "PCAUX_CS_SideResistance";
				displayName = "Allow INDEP to trigger";
				tooltip = "If enabled, Independent players can trigger civilian reactions.";
				expression = "_this setVariable ['PCAUX_CS_SideResistance', _value];";
				defaultValue = "false";
			};
			class SideCivilian : Checkbox
			{
				property = "PCAUX_CS_SideCivilian";
				displayName = "Allow CIV to trigger";
				tooltip = "If enabled, Civilian players can trigger civilian reactions.";
				expression = "_this setVariable ['PCAUX_CS_SideCivilian', _value];";
				defaultValue = "false";
			};
			class Radius : Edit
			{
				property = "PCAUX_CS_Radius";
				displayName = "Trigger Radius (m)";
				tooltip = "Distance at which a player can trigger the surrender check.";
				expression = "_this setVariable ['PCAUX_CS_Radius', _value];";
				typeName = "NUMBER";
				defaultValue = "3";
			};
			class WeightSurrender : Edit
			{
				property = "PCAUX_CS_WeightSurrender";
				displayName = "Surrender Weight";
				tooltip = "Relative chance to surrender.";
				expression = "_this setVariable ['PCAUX_CS_WeightSurrender', _value];";
				typeName = "NUMBER";
				defaultValue = "0.55";
			};
			class WeightFlee : Edit
			{
				property = "PCAUX_CS_WeightFlee";
				displayName = "Flee Weight";
				tooltip = "Relative chance to flee.";
				expression = "_this setVariable ['PCAUX_CS_WeightFlee', _value];";
				typeName = "NUMBER";
				defaultValue = "0.3";
			};
			class WeightResist : Edit
			{
				property = "PCAUX_CS_WeightResist";
				displayName = "Resist Weight";
				tooltip = "Relative chance to resist.";
				expression = "_this setVariable ['PCAUX_CS_WeightResist', _value];";
				typeName = "NUMBER";
				defaultValue = "0.15";
			};
			class FleeRadius : Edit
			{
				property = "PCAUX_CS_FleeRadius";
				displayName = "Flee Radius (m)";
				tooltip = "Distance civilians attempt to reach when fleeing.";
				expression = "_this setVariable ['PCAUX_CS_FleeRadius', _value];";
				typeName = "NUMBER";
				defaultValue = "80";
			};
			class ChangeSide : Checkbox
			{
				property = "PCAUX_CS_ChangeSide";
				displayName = "Switch sides on resist";
				tooltip = "When enabled, armed resisters join the OPFOR side.";
				expression = "_this setVariable ['PCAUX_CS_ChangeSide', _value];";
				defaultValue = "true";
			};
			class AutoSurrenderACE : Checkbox
			{
				property = "PCAUX_CS_AutoSurrenderACE";
				displayName = "Use ACE surrender";
				tooltip = "Automatically use ACE captives surrender if ACE is loaded.";
				expression = "_this setVariable ['PCAUX_CS_AutoSurrenderACE', _value];";
				defaultValue = "true";
			};
			class BoostSkills : Checkbox
			{
				property = "PCAUX_CS_BoostSkills";
				displayName = "Boost skills for armed resisters";
				tooltip = "Temporarily boost basic AI skills for armed resisters.";
				expression = "_this setVariable ['PCAUX_CS_BoostSkills', _value];";
				defaultValue = "true";
			};
			class ForceFirstShot : Checkbox
			{
				property = "PCAUX_CS_ForceFirstShot";
				displayName = "Force first shot";
				tooltip = "Forces the first shot when a civilian resists while armed.";
				expression = "_this setVariable ['PCAUX_CS_ForceFirstShot', _value];";
				defaultValue = "true";
			};
			class NoPathing : Checkbox
			{
				property = "PCAUX_CS_NoPathing";
				displayName = "Disable pathing for armed resist";
				tooltip = "Stops path planning when a civilian resists armed.";
				expression = "_this setVariable ['PCAUX_CS_NoPathing', _value];";
				defaultValue = "true";
			};
			class FastDrawCoef : Edit
			{
				property = "PCAUX_CS_FastDrawCoef";
				displayName = "Fast draw anim coef";
				tooltip = "Animation speed coefficient for armed resist draw.";
				expression = "_this setVariable ['PCAUX_CS_FastDrawCoef', _value];";
				typeName = "NUMBER";
				defaultValue = "1.6";
			};
			class FastDrawDuration : Edit
			{
				property = "PCAUX_CS_FastDrawDuration";
				displayName = "Fast draw duration (s)";
				tooltip = "Duration to keep the fast draw animation speed.";
				expression = "_this setVariable ['PCAUX_CS_FastDrawDuration', _value];";
				typeName = "NUMBER";
				defaultValue = "1";
			};
			class UseInstantPose : Checkbox
			{
				property = "PCAUX_CS_UseInstantPose";
				displayName = "Use instant pose change";
				tooltip = "Switches armed resisters immediately into a ready pose.";
				expression = "_this setVariable ['PCAUX_CS_UseInstantPose', _value];";
				defaultValue = "true";
			};
			class ArmedLoadouts : Edit
			{
				property = "PCAUX_CS_ArmedLoadouts";
				displayName = "Custom armed loadouts (SQF array)";
				tooltip = "Optional SQF array of [weapon, magazine, count] entries. Leave empty to use defaults.";
				expression = "_this setVariable ['PCAUX_CS_ArmedLoadouts', _value];";
				typeName = "STRING";
				defaultValue = "["3AS_ScatterGun_F", "3AS_8Rnd_EY30_Pellets", 2]";
			};
		};

		class ModuleDescription : ModuleDescription
		{
			description = "Attaches civilian surrender behaviour to synced civilians or all civilians if none are synced.";
			sync[] = {"AnyPerson"};
		};
	};
};

