class CfgPatches
{
	class 34thPC_3AS_ARC170
	{
		author="Phantom Company Modding Team, Yandere, Vasya";
		addonRootClass="34thPC_3AS_Overrides";
		requiredAddons[]=
		{
			"34thPC_3AS_Overrides",
			"3AS_ARC_170",
		};
		units[]={
			"3AS_ARC_170_base",
		};
	};
};

class CfgVehicles
{
	class 3AS_ARC_170_Base;
	class 34thPC_ARC_170 : 3AS_ARC_170_Base
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] ARC-170 (Imperial)";
		editorPreview="";
		scope=2;
		scopeCurator=2;
		crew="3AS_Clone_P2_Pilot"; //Bonus, swap to imperial
		side=1;
		hiddenselections[]=
		{
			"3as\3AS_ARC170\Data\Main_Frame_CO.paa",
			"3as\3AS_ARC170\Data\Wings_Engines_CO.paa",
			"3as\3AS_ARC170\Data\Guns_CO.paa"
		};
	};
};
