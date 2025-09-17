class CfgPatches
{
	class 34thPC_jms_T21B
	{
		author="Phantom Company Modding Team, Yandere, Vasya";
		addonRootClass="34thPC_jms_llte_patches";
		requiredAddons[]=
		{
			"JMSLLTE_weapons",
			"3AS_Weapons"
		};
		units[] =
		{
			"JMSLLTE_T21BBlasterRifle",
		};
	};
};

class CfgMagazines
{
	class 3AS_10Rnd_EM80_Mag;
	class 34thPC_T21B_20rnd_3AS_EM80_Mag : 3AS_10Rnd_EM80_Mag
	{
		count=20;
		displayName="[34th] T21B Energy cell";
	};
};

class CfgWeapons
{
	class JMSLLTE_T21BlasterRifle;
	class JMSLLTE_T21BBlasterRifle: JMSLLTE_T21BlasterRifle
	{
		magazines[]+=
		{
			"34thPC_T21B_20rnd_3AS_EM80_Mag"
		};
	};
};
