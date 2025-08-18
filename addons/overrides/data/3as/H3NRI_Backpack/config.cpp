class CfgPatches
{
	class 34thPC_3AS_H3NRI
	{
		author="Phantom Company Modding Team, Over Yandere";
		addonRootClass="34thPC_3AS_Overrides";
		requiredAddons[]=
		{
			"34thPC_3AS_Overrides",
			"3AS_Drones_H3NR1", // 3AS Drones
			"Indecisive_Armoury_units_IMPERIAL", // IDA
		};
		units[]={};
	};
};

class CfgVehicles
{
	class 3AS_H3NR1_Drone_Imperial;
	class 3AS_H3NR1_Drone_Scout_Imperial: 3AS_H3NR1_Drone_Imperial
	{
		displayName="[3AS] H3-NR1 Scout Drone";
		editorPreview="";
		forceInGarage=0;
		animationList[]=
		{
			"HideAttachmentBox",
			1
		};
		textureList[]=
		{
			"Imperial",
			1,
			"Brown",
			0,
			"Red",
			0
		};
		disableInventory=1;
		class assembleInfo
		{
			primary=1;
			base="";
			assembleTo="";
			displayName="";
			dissasembleTo[]=
			{
				"34thPC_Imperial_Droid_Backpack"
			};
		};
	};

	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
	class 3AS_B_H3NR1_Drone_Bag_F : Weapon_Bag_Base
	{

	};
	class 34thPC_Imperial_Droid_Backpack : 3AS_B_H3NR1_Drone_Bag_F
	{
		displayName="[34th] Imperial Scout Droid Pack";
		model="\Indecisive_Armoury_Units_IMPERIAL\Backpacks\IDA_Imperial_Backpack.p3d";
		picture="\Indecisive_Armoury_Units_IMPERIAL\Backpacks\Imp_Backpack_ui.paa";
		hiddenSelections[]=
		{
			"Straps",
			"BagRadio",
			"BagTop",
			"BagBottom"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"\Indecisive_Armoury_Units_IMPERIAL\Backpacks\IDA_Imperial_Backpack\IDA_Imperial_Backpack_BagTop_co.paa",
			"\Indecisive_Armoury_Units_IMPERIAL\Backpacks\IDA_Imperial_Backpack\IDA_Imperial_Backpack_BagBottom_co.paa"
		};
		class assembleInfo : assembleInfo
		{
			base="";
			displayName="Assemble H3NRI Drone";
			assembleTo="3AS_H3NR1_Drone_Scout_Imperial";
		};
	};
};
