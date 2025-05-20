class CfgPatches
{
	class 34thPC_GW_Overrides_BactaPatch
	{
		author="Phantom Company Modding Team, Over Yandere";
		addonRootClass="34thPC_Overrides";
		requiredAddons[]=
		{
			"34thPC_Overrides",
			"GW_Medical_Core", //@Galactic Warfare- Ace Medical Extension => GW_Medical_Core
		};
		units[]={};
	};
};

class ace_medical_treatment
{
	class Bandaging
	{
		//Override the GW Bacta Patch, will investigate making a different version later.
		class FieldDressing;
		class ExperimentalBactaPatch : FieldDressing
		{
			class Abrasion
			{
				effectiveness=5;
				reopeningChance=0;
				reopeningMinDelay=900;
				reopeningMaxDelay=1600;
			};
			class AbrasionMinor: Abrasion
			{
			};
			class AbrasionMedium: Abrasion
			{
				effectiveness=4;
				reopeningChance=0;
			};
			class AbrasionLarge: Abrasion
			{
				effectiveness=5;
				reopeningChance=0;
			};
			 class Avulsions: Abrasion {
				effectiveness = 5;
				reopeningChance = 0;
				reopeningMinDelay = 900;
				reopeningMaxDelay = 1600;
			};
			class AvulsionsMinor: Avulsions {
				effectiveness = 4;
				reopeningChance = 0;
				reopeningMinDelay = 900;
				reopeningMaxDelay = 1600;
			};
			class AvulsionsMedium: Avulsions {
				effectiveness = 4;
				reopeningChance = 0;
				reopeningMinDelay = 900;
				reopeningMaxDelay = 1600;
			};
			class AvulsionsLarge: Avulsions {
				effectiveness = 5;
				reopeningChance = 0;
				reopeningMinDelay = 900;
				reopeningMaxDelay = 1600;
			};
			class Contusion: Abrasion
			{
				effectiveness=4;
				reopeningChance=0;
				reopeningMinDelay=900;
				reopeningMaxDelay=1600;
			};
			class ContusionMinor: Contusion
			{
			};
			class ContusionMedium: Contusion
			{
			};
			class ContusionLarge: Contusion
			{
			};
			class Crush: Abrasion
			{
				effectiveness=5;
				reopeningChance=0;
				reopeningMinDelay=700;
				reopeningMaxDelay=1100;
			};
			class CrushMinor: Crush
			{
				effectiveness=4;
				reopeningChance=0;
			};
			class CrushMedium: Crush
			{
				effectiveness=3;
			};
			class CrushLarge: Crush
			{
				effectiveness=2.75;
				reopeningChance=0;
			};
			class Cut: Abrasion
			{
				effectiveness=6;
				reopeningChance=0;
				reopeningMinDelay=800;
				reopeningMaxDelay=1100;
			};
			class CutMinor: Cut
			{
			};
			class CutMedium: Cut
			{
				effectiveness=5;
				reopeningChance=0;
			};
			class CutLarge: Cut
			{
				effectiveness=4;
				reopeningChance=0;
			};
			class Laceration: Abrasion
			{
				effectiveness=4;
				reopeningChance=0;
				reopeningMinDelay=600;
				reopeningMaxDelay=2000;
			};
			class LacerationMinor: Laceration
			{
			};
			class LacerationMedium: Laceration
			{
				effectiveness=3;
			};
			class LacerationLarge: Laceration
			{
				effectiveness=2.5;
				reopeningChance=0;
			};
			class velocityWound: Abrasion
			{
				effectiveness=4;
				reopeningChance=0;
				reopeningMinDelay=900;
				reopeningMaxDelay=2000;
			};
			class velocityWoundMinor: velocityWound
			{
			};
			class velocityWoundMedium: velocityWound
			{
				effectiveness=2;
			};
			class velocityWoundLarge: velocityWound
			{
				effectiveness=2.75;
			};
			class punctureWound: Abrasion
			{
				effectiveness=4;
				reopeningChance=0;
				reopeningMinDelay=1000;
				reopeningMaxDelay=3000;
			};
			class punctureWoundMinor: punctureWound
			{
			};
			class punctureWoundMedium: punctureWound
			{
				effectiveness=4.5;
			};
			class punctureWoundLarge: punctureWound
			{
				effectiveness=4;
			};
		};
	};
};
class ace_medical_treatment_actions
{
	class BasicBandage;
	class ExperimentalBactaPatch : BasicBandage
	{
		displayName="[PC] Experimental Bacta Patch";
		displayNameProgress="Administering aid...";
		items[]=
		{
			"PC_ExperimentalBactaPatch"
		};
		litter[]={};
	};
};

class CfgVehicles
{
	class Item_Base_F;
	class PC_ExperimentalBactaPatch_Item : Item_Base_F
	{
		scope=2;
		scopeCurator=2;
		displayName="[PC] Experimental Bacta Patch";
		author="Yandere";
		class TransportItems
		{
			class _xx_GW_BactaPatch
			{
				name="PC_ExperimentalBactaPatch";
				count=1;
			};
		};
	};
};

class CfgWeapons
{
	class ItemCore;
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class GW_BactaPatch;
	class PC_ExperimentalBactaPatch: GW_BactaPatch
	{
		scope=2;
		author="Yandere";
		displayName="[PC] Experimental Bacta Patch";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=1;
		};
	};
};
