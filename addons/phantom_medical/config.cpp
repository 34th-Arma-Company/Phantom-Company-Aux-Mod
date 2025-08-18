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
		class Millafline : Morphine
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
		class Adenosine
		{
			painReduce = 0;
			hrIncreaseLow[] = {-7, -10};
			hrIncreaseNormal[] = {-15, -30};
			hrIncreaseHigh[] = {-15, -35};
			timeInSystem = 120;
			timeTillMaxEffect = 15;
			maxDose = 5;
			dose = 1;
			incompatibleMedication[] = {};
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
		class Fentanyl
		{
			painReduce=1;
			hrIncreaseLow[]={-10,-5};
			hrIncreaseNormal[]={-15,-10};
			hrIncreaseHigh[]={-20,-10};
			timeInSystem=900;
			timeTillMaxEffect=20;
			maxDose=1;
			maxDoseDeviation=1;
			incompatibleMedication[]={};
			viscosityChange=-10;
			onOverDose="";
			opioidRelief=0.2;
			opioidEffect=0.18000001;
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
		class Penthrox
		{
			painReduce=0.60000002;
			hrIncreaseLow[]={0,-5};
			hrIncreaseNormal[]={-5,-10};
			hrIncreaseHigh[]={-5,-15};
			timeInSystem=300;
			timeTillMaxEffect=20;
			maxDose=4;
			incompatibleMedication[]={};
			viscosityChange=5;
			onOverDose="";
			maxRelief=0.60000002;
		};
	};
};

class ACE_Medical_Treatment_Actions
{
	class BasicBandage;
	class Morphine;
	class Splint : BasicBandage
	{
		displayName = "Bonemer";
		displayNameProgress = "Applying Bonemer";
		category = "bandage";
	};
	class Millafline : Morphine
	{
		displayName="Injector (Millafline)";
		displayNameProgress="Using Millafline Injector";
		items[]=
		{
			"PC_Injector_Millafline"
		};
	};

	class Epinephrine: Morphine
	{
		displayName = "Stim (Polybiotic)";
		displayNameProgress = "Injecting Polybiotic";
		callbackSuccess="kat_pharma_fnc_medication";
		items[]=
		{
			"PC_Stim_Polybiotic"
		};
	};

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
	class Norepinephrine: EACA
	{
		displayName="Stim (Kyrprax)";
		displayNameProgress="Using Kyrprax Stim";
		items[]=
		{
			"PC_Stim_Kyrprax"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class PhenylephrineAuto: Morphine
	{
		displayName="Injector (Plethyl Nitrate)";
		displayNameProgress="Using Plethyl Nitrate Injector";
		items[]=
		{
			"PC_Injector_Plethyl_Nitrate"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class Naloxone: Carbonate
	{
		displayName="Injector (Antitox)";
		displayNameProgress="Using Antitox Injector";
		items[]=
		{
			"PC_Injector_Antitox"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class Adenosine : Morphine
	{
		displayName = "Injector (Metacycline)";
		displayNameProgress = "Injecting (Metacycline)";
		items[]=
		{
			"PC_Injector_Metacycline"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class Ketamine: EACA
	{
		displayName = "Sansanna Spice";
		displayNameProgress = "Using Spice";
		items[]=
		{
			"PC_Sansanna_Spice"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class Fentanyl: EACA
	{
		displayName = "Felucian Spice";
		displayNameProgress = "Using Spice";
		items[]=
		{
			"PC_Felucian_Spice"
		};
		callbackSuccess="kat_pharma_fnc_medication";
	};

	class Penthrox : Morphine
	{
		displayName = "Inhaler (Nyex)";
		displayNameProgress = "Using Nyex Inhaler";
		items[]=
		{
			"PC_Inhaler_Nyex"
		};
	};
};

class CfgVehicles
{
	class Item_Base_F;
	class ACE_splintItem: Item_Base_F {
		displayName = "Bonemer";
	};
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

	class PC_Injector_Millafline_Item : Item_Base_F
	{
		displayName="Injector (Millafline)";
		author="Over Yandere";
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		vehicleClass="Items";
		class _xx_PC_Injector_Millafline
		{
			name="PC_Injector_Millafline";
			count=1;
		};
	};

	class PC_Injector_Metacycline_Item : Item_Base_F
	{
		displayName="Injector (Metacycline)";
		author="Over Yandere";
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		vehicleClass="Items";
		class _xx_PC_Injector_Metacycline
		{
			name="PC_Injector_Metacycline";
			count=1;
		};
	};

	class PC_Stim_Polybiotic_Item : Item_Base_F
	{
		displayName="Stim (Polybiotic)";
		author="Over Yandere";
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="kobra\442_misc\medical\StimPolybiotics.p3d";
		vehicleClass="Items";
		class _xx_PC_Stim_Polybiotic
		{
			name="PC_Stim_Polybiotic";
			count =1;
		};
	};

	class PC_Stim_Kyrprax_Item : Item_Base_F
	{
		displayName="Stim (Kyrprax)";
		author="Over Yandere";
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\TK\GW\GW_Medical_Assets\StimYellow.p3d";
		vehicleClass="Items";
		class _xx_PC_Stim_Kyrprax
		{
			name="PC_Stim_Kyrprax";
			count=1;
		};
	};

	class PC_Injector_Antitox_Item : Item_Base_F
	{
		displayName="Injector (Antitox)";
		author="Over Yandere";
		editorcategory = "EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
		vehicleClass="Items";
		class _xx_PC_Injector_Antitox
		{
			name="PC_Injector_Antitox";
			count=1;
		};
	};

	class PC_Injector_Plethyl_Nitrate_Item : Item_Base_F
	{
		displayName="Injector (Plethyl Nitrate)";
		author="Over Yandere";
		editorcategory="EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		vehicleClass="Items";
		class _xx_PC_Injector_Plethyl_Nitrate
		{
			name="PC_Injector_Plethyl_Nitrate";
			count=1;
		};
	};

	class PC_Sansanna_Spice_Item : Item_Base_F
	{
		displayName="Sansanna Spice";
		author="Over Yandere";
		editorcategory="EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model= "\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		vehicleClass="Items";
		class _xx_PC_Sansanna_Spice
		{
			name="PC_Sansanna_Spice";
			count=1;
		};
	};

	class PC_Felucian_Spice_Item : Item_Base_F
	{
		displayName="Felucian Spice";
		author="Over Yandere";
		editorcategory="EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model= "\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
		vehicleClass="Items";
		class _xx_PC_Felucian_Spice
		{
			name="PC_Felucian_Spice";
			count=1;
		};
	};

	class PC_Inhaler_Nyex_Item : Item_Base_F
	{
		displayName="Inhaler (Nyex)";
		author="Over Yandere";
		editorcategory="EdCat_Supplies";
		editorsubcategory = "EdSubcat_Medicine";
		model="\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		vehicle="Items";
		class _xx_PC_Inhaler_Nyex
		{
			name="PC_Inhaler_Nyex";
			count=15;
		};
	};
};

class CfgWeapons
{
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;

	class ACE_splint: ACE_ItemCore {
		displayName = "Bonemer";
		descriptionShort = "A synthetic substance used to repair, replace, or supplement bone";
	};

	//EACA Reskin
	class kat_EACA;
	class PC_Injector_Dermaseal:kat_EACA
	{
		scope=2;
		displayName="Injector (Dermaseal)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_blue_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
		descriptionShort="Dermaseal covers and protects wounds";
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
		descriptionShort="Coagulin is a chemical coumpound that causes clotting";
		ACE_isMedicalItem=1;
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};
	//Morphine Reskin
	class PC_Injector_Millafline : ACE_ItemCore
	{
		scope=2;
		displayName="Injector (Millafline)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_red_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		descriptionShort="Millafline is an extract derived from Naboo's Millaflower, provides pain relief";
		ACE_isMedicalItem=1;
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=1;
		};
	};

	//Epinephrine Reskin
	class PC_Stim_Polybiotic : ACE_ItemCore
	{
		scope=2;
		displayName="Stim (Polybiotic)";
		model="kobra\442_misc\medical\StimPolybiotics.p3d";
		picture="\kobra\442_misc\medical\ui\stim_polybiotics_ui.paa";
		descriptionShort="Polybiotic is synthetic mixture that raises heart rate";
		ACE_isMedicalItem=1;
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=1;
		};
	};

	//Norepinephrine Reskin
	class PC_Stim_Kyrprax : ACE_ItemCore
	{
		scope=2;
		displayName="Stim (Kyrprax)";
		model="\TK\GW\GW_Medical_Assets\StimYellow.p3d";
		picture="\TK\GW\GW_Medical_Assets\ui\stim_yellow_ui_ca.paa";
		descriptionShort="Kyrprax is a compound derived from hormones, used to raise heart rate and blood pressure";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass = 1;
		};
	};

	//Adenosine Reskin
	class PC_Injector_Metacycline : ACE_ItemCore
	{
		scope=2;
		displayName="Injector (Metacycline)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_red_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		descriptionShort="Reduces Heartrate, and treats SVT.";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};

	//Naloxone Reskin
	class PC_Injector_Antitox : ACE_ItemCore
	{
		scope=2;
		displayName="Injector (Antitox)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_yellow_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
		descriptionShort="Antitox counteracts the effects of spice";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};

	//Phenylephrine Reskin
	class PC_Injector_Plethyl_Nitrate : ACE_ItemCore
	{
		scope=2;
		displayName="Injector (Plethyl Nitrate)";
		picture="\TK\GW\GW_Medical_Assets\ui\injector_red_ui_ca.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		descriptionShort="Plethyl Nitrate raises blood pressure.";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};

	//Ketamine Reskin
	class PC_Sansanna_Spice : ACE_ItemCore
	{
		scope=2;
		displayName="Sansanna Spice";
		picture="\z\34thpc\addons\phantom_medical\data\SasannaSpice.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
		descriptionShort="Dissociative pain relief";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};

	//Fentynal Reksin
	class PC_Felucian_Spice : ACE_ItemCore
	{
		scope=2;
		displayName="Felucian Spice";
		picture="\z\34thpc\addons\phantom_medical\data\FelucianSpice.paa";
		model="\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
		descriptionShort="Provides pain relief, at a cost";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};

	//Penthrox Reskin
	class PC_Inhaler_Nyex : ACE_ItemCore
	{
		scope=2;
		displayName="Inhaler (Nyex)";
		descriptionShort="Temporarily relieves pain.";
		model="\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		picture="\z\34thpc\addons\phantom_medical\data\Nyex.paa";
		class ItemInfo : CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};
};
