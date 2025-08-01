class CfgPatches
{
	class 34thPC_phantom_medical
	{
		author="34th PC Modding Team";
		units[]=
		{
		};
		requiredAddons[] =
		{
			"ace_medical_status",
			"ace_medical_damage",
			"ace_apl",
			"kat_pharma",
			"GW_Medical_Core", //@Galactic Warfare- Ace Medical Extension => GW_Medical_Core
			"GW_Kobra_Ace_Medical_Core", //@Galactic Warfare- Ace Medical Extension (Kobra Patch)
			"34thPC_Overrides",
		};
	};
};

class ace_Medical_Treatment
{
	class medication
	{
		painReduce=0;
		hrIncreaseLow[]={0,0};
		hrIncreaseNormal[]={0,0};
		hrIncreaseHigh[]={0,0};
		timeInSystem=120;
		timeTillMaxEffect=30;
		maxDose=4;
		maxDoseDeviation=2;
		dose=1;
		onOverDose="";
		viscosityChange=0;
		alphaFactor=0;
		maxRelief=0;
		opioidRelief=0;
		opioidEffect=0;
		class Epinephrine
		{
			painReduce=0;
			hrIncreaseLow[]={10,20};
			hrIncreaseNormal[]={10,50};
			hrIncreaseHigh[]={10,40};
			timeInSystem=120;
			timeTillMaxEffect=10;
			maxDose=6;
			maxDoseDeviation=4;
			incompatibleMedication[]={};
			alphaFactor=-0.15000001;
			onOverDose="";
		};
		class Morphine
		{
			painReduce=0.80000001;
			hrIncreaseLow[]={-10,-20};
			hrIncreaseNormal[]={-10,-30};
			hrIncreaseHigh[]={-10,-35};
			timeInSystem=900;
			timeTillMaxEffect=30;
			maxDose=4;
			maxDoseDeviation=4;
			incompatibleMedication[]={};
			viscosityChange=-10;
			opioidRelief=0.1;
		};
		class TXA
		{
			painReduce=0;
			hrIncreaseLow[]={0,0};
			hrIncreaseNormal[]={0,0};
			hrIncreaseHigh[]={0,0};
			timeInSystem=120;
			timeTillMaxEffect=5;
			maxDose=3;
			incompatibleMedication[]={};
			viscosityChange=0;
			onOverDose="";
		};
		class Norepinephrine
		{
			painReduce=0;
			hrIncreaseLow[]={0,5};
			hrIncreaseNormal[]={5,15};
			hrIncreaseHigh[]={5,10};
			timeInSystem=360;
			timeTillMaxEffect=15;
			maxDose=12;
			incompatibleMedication[]={};
			viscosityChange=25;
			alphaFactor=-0.30000001;
			onOverDose="";
		};
		class PhenylephrineAuto
		{
			painReduce=0;
			hrIncreaseLow[]={-5,-10};
			hrIncreaseNormal[]={-5,-10};
			hrIncreaseHigh[]={-10,-15};
			timeInSystem=360;
			timeTillMaxEffect=15;
			maxDose=6;
			maxDoseDeviation=4;
			incompatibleMedication[]={};
			viscosityChange=25;
			alphaFactor=-0.30000001;
		};
		class Ketamine
		{
			painReduce=0.80000001;
			hrIncreaseLow[]={5,10};
			hrIncreaseNormal[]={10,15};
			hrIncreaseHigh[]={10,15};
			timeInSystem=900;
			timeTillMaxEffect=15;
			maxDose=2;
			maxDoseDeviation=2;
			incompatibleMedication[]={};
			viscosityChange=10;
			onOverDose="";
			opioidEffect=0.17;
		};
		class EACA
		{
			painReduce=0;
			hrIncreaseLow[]={0,0};
			hrIncreaseNormal[]={0,0};
			hrIncreaseHigh[]={0,0};
			timeInSystem=600;
			timeTillMaxEffect=15;
			maxDose=10;
			incompatibleMedication[]={};
			viscosityChange=0;
			onOverDose="";
		};
	};
};

class ACE_Medical_Treatment_Actions
{
	class Carbonate;
	class EACA : Carbonate
	{
		displayName="Injector (Dermaseal)";
		displayNameProgress="Using Dermaseal Injector";
		items[]=
		{
			"PC_Injector_Dermaseal"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};
	class TXA : EACA
	{
		displayName="Injector (Coagulin)";
		displayNameProgress="Using Coagulin Injector";
		items[]=
		{
			"PC_Injector_Coagulin"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};
};

class CfgVehicles
{
	class Item_Base_F;
	class PC_Injector_Dermaseal_Item : Item_Base_F
	{
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		displayName = "Injector (Dermaseal)";
		author = "Over Yandere";
		model = "\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
		vehicleClass="Items";
		class TransportItems
		{
			class _xx_PC_Injector_Dermaseal_Sealant
			{
				name="PC_Injector_Dermaseal";
				count=1;
			};
		};
	};
	class PC_Injector_Coagulin_Item : PC_Injector_Dermaseal_Item
	{
		displayName = "Injector (Coagulin)";
		author="Over Yandere";
		model="\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
		class TransportItems
		{
			class _xx_PC_Injector_Coagulin
			{
				name="PC_Injector_Coagulin";
				count=1;
			};
		};
	};
};

class CfgWeapons
{
	class CBA_MiscItem_ItemInfo;

	//EACA Reskin
	class kat_EACA;
	class PC_Injector_Dermaseal:kat_EACA
	{
		scope=2;
		displayName="Injector (Dermaseal)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_blue_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
		descriptionShort="$STR_kat_pharma_EACA_DescShort";
		ACE_isMedicalItem=1;
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0.2;
		};
	};

	//TXA Reskin
	class PC_Injector_Coagulin : PC_Injector_Dermaseal
	{
		displayName="Injector (Coagulin)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_yellow_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
		descriptionShort="$STR_kat_pharma_TXA_DescShort";
		ACE_isMedicalItem=1;
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};
};
