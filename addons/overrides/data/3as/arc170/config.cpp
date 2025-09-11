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
			"3AS_ARC_170_Base",
		};
	};
};

class CfgVehicles
{
	class 3AS_ARC_170_Base;
	class 34thPC_ARC_170_Base : 3AS_ARC_170_Base
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] ARC-170 Base";
		crew="3AS_Imperial_TIE_Pilot_F";
		faction="34thPC_FactionPhantom_Faction";
		class TextureSources
		{
			class Imperial
			{
				displayName="Imperial";
				author="34thPC Mod Dev Team";
				textures[]=
				{
					"overrides\data\3as\arc170\textures\Main_Frame_CO.paa",
					"overrides\data\3as\arc170\textures\Wings_Engines_CO.paa",
					"overrides\data\3as\arc170\textures\Guns_CO.paa"
				};
				factions[]=
				{
					"34thPC_FactionPhantom_Faction"
				};
			};
		};
	};
	class 34thPC_ARC_170_Imperial : 34thPC_ARC_170_Base
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] ARC-170 (Imperial)";
		editorPreview="";
		scope=2;
		scopeCurator=2;
		crew="3AS_Imperial_TIE_Pilot_F";
		side=1;
		faction="34thPC_FactionPhantom_Faction";
		hiddenselectionstextures[]=
		{
			"overrides\data\3as\arc170\textures\Main_Frame_CO.paa",
			"overrides\data\3as\arc170\textures\Wings_Engines_CO.paa",
			"overrides\data\3as\arc170\textures\Guns_CO.paa"
		};
		textureList[]=
		{
			"Republic",
			0,
			"Blue",
			0,
			"Green",
			0,
			"Orange",
			0,
			"Yellow",
			0,
			"Imperial",
			1,
		};
	};
};
