class CfgPatches
{
	class 34thPC_jms_TL50
	{
		author="Phantom Company Modding Team, Yandere";
		addonRootClass="34thPC_jms_llte_patches";
		requiredAddons[]=
		{
			"JMSLLTE_weapons",
		};
	};
};

class CfgAmmo
{
	class JMSLLTE_tl50_Ammo;

	class 34thPC_tl50_ammo : JMSLLTE_tl50_Ammo
	{
		hit=12; //redefine hit value
		indirectHit=0; //Changed to 0 from 0.1
		indirectHitRange=0; //Also reduced to 0
		caliber=2.2;
	};
};

class CfgMagazines
{
	class JMSLLTE_Tl50_40rnd_Mag;
	class 34thPC_TL50_40rnd_Mag : JMSLLTE_Tl50_40rnd_Mag
	{
		ammo="34thPC_tl50_ammo";
		displayName="[34th] TL50 Energy cell";
	};
};

class CfgWeapons
{
	class JMSLLTE_BlasterRifle_Base;
	class JMSLLTE_tl50: JMSLLTE_BlasterRifle_Base
	{
		magazines[]=
		{
			"JMSLLTE_Tl50_40rnd_Mag",
			"34thPC_TL50_40rnd_Mag"
		};
	};
};
