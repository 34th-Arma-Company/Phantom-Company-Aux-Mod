class CfgPatches
{
	class 34thPC_jms_E11D
	{
		author="Phantom Company Modding Team, Yandere";
		addonRootClass="34thPC_jms_llte_patches";
		requiredAddons[]=
		{
			"JMSLLTE_weapons",
			"3AS_Weapons"
		};
		units[] =
		{
			"JMSLLTE_e11d",
		};
	};
};

class CfgWeapons
{
	class JMSLLTE_BlasterRifle_Base;
	class JMSLLTE_e11d: JMSLLTE_BlasterRifle_Base
	{
		magazines[]+=
		{
			"3AS_45Rnd_EM50_Mag"
		};
	};
};
