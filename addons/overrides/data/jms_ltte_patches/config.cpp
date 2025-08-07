class CfgPatches
{
	class 34thPC_jms_llte_patches
	{
		author="Phantom Company Modding Team, Vasya";
		addonRootClass="34thPC_Overrides";
		requiredAddons[]=
		{
			"34thPC_Overrides",
			"JMSLLTE_weapons",
			"3AS_Weapons",
		};
	};
};

class CfgWeapons
{
	#include "config_weapons.cpp"
};
