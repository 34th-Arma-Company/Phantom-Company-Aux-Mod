class CfgPatches
{
	class 34thPC_jms_TL50
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
			"JMSLLTE_tl50",
		};
	};
};

class CfgWeapons
{
	class JMSLLTE_BlasterRifle_Base;
	class JMSLLTE_tl50: JMSLLTE_BlasterRifle_Base
	{
		magazines[]+=
		{
			"3AS_45Rnd_EM50_Mag"
		};
	};
};
