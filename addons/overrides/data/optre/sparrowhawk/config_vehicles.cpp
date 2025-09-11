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
	class OPTRE_AV22A_Sparrowhawk;
	class 34thPC_Sparrowhawk_Base : OPTRE_AV22A_Sparrowhawk
	{
		scope=0;
		dlc="34th";
		author="34thPC Mod Dev Team";
		displayName="34th Star Wing Base";
		//Do changes for hud and or flight model here
	};

	class 34thPC_Imperial_StarWing : 34thPC_Sparrowhawk_Base
	{
		scope = 2;
		scopecurator = 2;
		scopearsenal = 2;
		displayName="[34th] Imperial-class AG-22 Star Wing";
		textures[] =
		{
			"overrides\data\optre\sparrowhawk\textures\Body_01_co.paa",
			"overrides\data\optre\sparrowhawk\textures\Body_02_co.paa",
			"overrides\data\optre\sparrowhawk\textures\Body_03_co.paa",
			"overrides\data\optre\sparrowhawk\textures\Body_04_co.paa",
		};
	};
};
