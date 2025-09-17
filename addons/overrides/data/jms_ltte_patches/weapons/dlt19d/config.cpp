class CfgPatches
{
	class 34thPC_jms_DLT19D
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
			"JMSLLTE_DLT19dRifle",
		};
	};
};

class CfgWeapons
{
	class JMSLLTE_BlasterRifle_Base;
	class JMSLLTE_DLT19dRifle: JMSLLTE_BlasterRifle_Base
	{
		magazines[]+=
		{
			"3AS_10Rnd_EM100_DLT19X_Mag"
		};
	};
};
