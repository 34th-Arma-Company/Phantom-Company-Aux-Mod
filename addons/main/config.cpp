#include "script_version.hpp"
class CfgPatches
{
	class 34thSOD_Main
	{
		name = "main";
		author = "34th SOD Modding Team";
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
		};
		VERSION_CONFIG;
	};
};

class CfgSettings {
	class CBA {
		class Versioning { // https://github.com/CBATeam/CBA_A3/wiki/Versioning-System
			class 34thSOD_Main {
				main_addon = "34thSOD_Main";
			};
		};
	};
};
