class CfgPatches
{
	class 34thPC_Sparrowhawk
	{
		author="Phantom Company Modding Team, Yandere, Vasya";
		addonRootClass="34thPC_optre_patches";
		requiredAddons[]=
		{
			"34thPC_optre_patches",
			"OPTRE_Vehicles_Sparrowhawk",
		};
		units[]={
		};
	};
};

class CfgVehicles
{
	class OPTRE_AV22_Sparrowhawk_Base;
	class 34thPC_Sparrowhawk_Base : OPTRE_AV22_Sparrowhawk_Base
	{
		scope=0;
		dlc="34th";
		author="34thPC Mod Dev Team";
		displayName="Tie Opressor Base";
		//Do changes for hud and or flight model here
	};

	class 34thPC_TIE_Opressor : 34thPC_Sparrowhawk_Base
	{
		scope=2;
		displayName="[34th] Tie Opressor";
	};
};
