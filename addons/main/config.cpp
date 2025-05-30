#include "script_version.hpp"
class CfgPatches
{
	class 34thPC_Main
	{
		name = "main";
		author = "34th Arma Company Mod Dev Team";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"34thPC_Overrides",
			"34thPC_FactionPhantom"
		};
		VERSION_CONFIG;
	};
};

class CfgSettings
{
	class CBA{
		class versioning { // https://github.com/CBATeam/CBA_A3/wiki/Versioning-System
			class 34thPC_Main {
				main_addon = "34thPC_Main";
			};
		};
	};
};
