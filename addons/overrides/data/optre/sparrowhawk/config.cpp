class CfgPatches
{
	class 34thPC_Sparrowhawk
	{
		author="Phantom Company Modding Team, Yandere, Vasya";
		addonRootClass="34thPC_optre_patches";
		requiredAddons[]=
		{
			"34thPC_optre_patches",
			"OPTRE_Vehicles_Sparrowhawk",
			"3AS_LAAT"
		};
		units[]={
			"34thPC_Imperial_StarWing"
		};
	};
};

class CfgWeapons {
	class OPTRE_M6_Laser;
	class ISB_Exp_Laser: OPTRE_M6_Laser {
		displayName = "ISB Classified Beam Emmitter";
		magazineReloadTime = 3;
		burst = 50;
		magazines[]=
		{
			"laserMag"
		};
	};
};

class CfgMagazines{
	class OPTRE_SpLaser_Battery;
	class laserMag: OPTRE_SpLaser_Battery {
		count = 50;
		ammo = "laserAmmo";
	};
};

class CfgAmmo {
	class OPTRE_SpLaserAmmo;
  class laserAmmo: OPTRE_SpLaserAmmo {
    	hit = 500;
		indirecthit = 50;
		indirecthitrange = 3;
		caliber = 15;
		deflect = 0;
  };
};



class CfgVehicles
{
	class Components;
	class Turrets;
	class CopilotTurret;
	class OPTRE_AV22A_Sparrowhawk;
	class 3AS_Patrol_LAAT_Base;

	class 34thPC_Imperial_StarWing_Base : OPTRE_AV22A_Sparrowhawk
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] Imperial-class AG-134 Star Sparrow";
		editorPreview="";
		scope=0;
		scopeCurator=0;
		crew="3AS_Imperial_TIE_Pilot_F";
		side=1;
		faction="34thPC_FactionPhantom_Faction";
		tas_max_impulse = 800;
		tas_impulse_break = 100;
		tas_can_impulse = 1;
		radarType = 8;
		//Do changes for hud and or flight model here.... YOU AREN'T MY REAL DAD - Disqo
		class UserActions
		{
			//removing OPTRE thruster actions and Adding 3AS Impulse actions
			class impulseOn
			{
				showWindow = 0;
				hideOnUse = 1;
				priority = 9;
				displayName = "Activate Impulse";
				position = "pilotview";
				radius = 6;
				onlyforplayer = 1;
				condition = "(player == driver this) AND !(this getvariable [""laat_boosting"",false])";
				statement = "[] spawn TAS_fnc_Impulse;";
			};
			class impulseOff
			{
				showWindow = 0;
				hideOnUse = 1;
				priority = 9;
				displayName = "Deactivate Impulse";
				position = "pilotview";
				radius = 6;
				onlyforplayer = 1;
				condition = "(player == driver this) AND (this getvariable [""laat_boosting"",false])";
				statement = "[] spawn TAS_fnc_ImpulseOff;";
			};
		};
		hiddenSelectionsTextures[] =
		{
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Body_01_co.paa",
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Body_02_co.paa",
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Body_03_co.paa",
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Body_04_co.paa",
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Body_05_CO.paa",
			//"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Autocannon_CO.paa", STINKY DONT UN-COMMENT THIS
			"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Feed_Autocannon_CO.paa",
			//"\z\34thpc\addons\overrides\data\optre\sparrowhawk\textures\Heavy_Autocannon_CO.paa", STINKY DONT UN-COMMENT THIS
		};
		tf_range=25000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		enableRadio=1;
		weapons[] = {"3as_LAAT_Medium_Canon","CMFlareLauncher"};
		magazines[] = {"240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","3as_LAAT_1000Rnd_Medium_shells","3as_LAAT_1000Rnd_Medium_shells","3as_LAAT_1000Rnd_Medium_shells","3as_LAAT_1000Rnd_Medium_shells"};
		class SensorTemplateIR;
		class SensorTemplateVisual;
		class SensorTemplatePassiveRadar;
		class SensorTemplateActiveRadar;
		class SensorTemplateAntiRadiation;
		class SensorTemplateLaser;
		class SensorTemplateNV;
		class DefaultVehicleSystemsDisplayManagerLeft;
		class DefaultVehicleSystemsDisplayManagerRight;
		class Components: Components
		{
			class TransportPylonsComponent
			{
				UIPicture="\OPTRE_Vehicles_Air\Sparrowhawk\sparrowhawkPylonImage.paa";
				class pylons
				{
					class WingPylonRight1
					{
						maxweight=560;
						hardpoints[]=
						{
							//"B_AGM65_DUAL",
                            "B_AGM65_RAIL",
                            "B_HARM_RAIL",
                            "B_SHIEKER",
                            //"O_MISSILE_PYLON",
                            //"O_SKYFIRE",
                            //"SCALPEL_1RND",
                            //"UNI_SCALPEL",
                            //"REP_AGM_RAIL",
                            //"IMP_AGM_RAIL",
						};
						attachment="";
						bay=-1;
						priority=3;
						UIposition[]={0.34999999,0.1};
						turret[]={};
					};
					class WingPylonRight2: WingPylonRight1
					{
						priority=2;
						UIposition[]={0.30000001,0.134};
						attachment="";
					};
					class WingPylonRight3: WingPylonRight1
					{
						priority=1;
						UIposition[]={0.34999999,0.167};
						attachment="";
					};
					class WingPylonLeft3: WingPylonRight3
					{
						mirroredMissilePos=3;
						UIposition[]={0.34999999,0.40000001};
					};
					class WingPylonLeft2: WingPylonRight2
					{
						mirroredMissilePos=2;
						UIposition[]={0.30000001,0.43399999};
					};
					class WingPylonLeft1: WingPylonRight1
					{
						mirroredMissilePos=1;
						UIposition[]={0.34999999,0.46700001};
					};
				};
			};
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=100;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=100;
							maxRange=16000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=160;
						angleRangeVertical=90;
						maxTrackableSpeed=100;
						componentType="IRSensorComponent";
						typeRecognitionDistance=2000;
						maxFogSeeThrough=0.995;
						color[]={1,0,0,1};
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=50;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=50;
							maxRange=16000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=160;
						angleRangeVertical=90;
						maxTrackableSpeed=100;
						aimDown=1;
						animDirection="pilotCameraRotY";
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						componentType="PassiveRadarSensorComponent";
						class AirTarget
						{
							minRange=300;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=300;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
						angleRangeHorizontal=160;
						angleRangeVertical=90;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						color[]={0.5,1,0.5,0.5};
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
						allowsMarking=0;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=300;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=300;
							maxRange=1600;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
						angleRangeHorizontal=160;
						angleRangeVertical=90;
						groundNoiseDistanceCoef=0.2;
					};
					class AntiRadiationSensorComponent: SensorTemplateAntiRadiation
					{
						class AirTarget
						{
							minRange=300;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=300;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableATL=100;
						maxTrackableSpeed=60;
						angleRangeHorizontal=160;
						angleRangeVertical=90;
					};
				};
			};
   		};
	};

	class 34thPC_Imperial_StarWing : 34thPC_Imperial_StarWing_Base {
		author="34thPC Mod Dev Team";
		displayName="[34th] Imperial-class AG-134 Star Sparrow";
		editorPreview="";
		scope=2;
		scopeCurator=2;
		scopeArsenal=2;
		crew="3AS_Imperial_TIE_Pilot_F";
		faction="34thPC_FactionPhantom_Faction";
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				weapons[]=
				{
					"ISB_Exp_Laser",
					"Laserdesignator_mounted"
				};
				magazines[]=
				{
					"laserMag",
					"laserMag",
					"laserMag",
					"laserMag",
					"laserMag",
					"laserMag",

					"Laserbatteries"
				};
			};
		};
	};
};
