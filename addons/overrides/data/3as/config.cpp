class CfgPatches
{
	class 34thPC_3AS_Overrides
	{
		author="Phantom Company Modding Team, Over Yandere";
		addonRootClass="34thPC_Overrides";
		requiredAddons[]=
		{
			"34thPC_Overrides",
			"3AS_Compat_Terrains", "3AS_Structures_FOB" //@3AS (Beta test) => 3AS_Cpompat_Terrains, 3AS_Terrains (Beta) => 3AS_Structures => FOB
		};
		units[]={};
	};
};

class CfgVehicles
{
	class 3AS_FOB_Turret_Base_Prop;
	class 3AS_Fusion_Turret_Base: 3AS_FOB_Turret_Base_Prop
	{
		displayName="Fusion Cutter Turret Base";
		TAS_fusionFortify_time=30;
		TAS_fusionFortify_turret="3AS_StationaryTurret";
		scope=2;
		scopeCurator=2;
	};
};
