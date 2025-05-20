class CfgPatches
{
	class 34thPC_Overrides
	{
		author="34th PC Modding Team";
		units[]=
		{
			"34thPC_TieLN_1",
			"34thPC_TieLN_2",
			"34thPC_TieLN_3",
			"34thPC_TieLN_4",
			"34thPC_TieLN_5",
			"34thPC_TieLN_6",
			"34thPC_TieLN_7",
			"34thPC_TieBomber_1",
			"34thPC_TieBomber_2",
		};
		requiredAddons[] =
		{
			"WM_Imperial_Vehicles",
			"34thPC_FactionPhantom",
			"3AS_Imperial_Air",
		};
	};
};
class CfgVehicles
{
	#include "data\config_vehicles.hpp"
};

