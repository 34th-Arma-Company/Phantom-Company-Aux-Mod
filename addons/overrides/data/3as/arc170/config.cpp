class CfgPatches
{
	class 34thPC_3AS_ARC170
	{
		author="Phantom Company Modding Team, Yandere, Vasya";
		addonRootClass="34thPC_3AS_Overrides";
		requiredAddons[]=
		{
			"34thPC_3AS_Overrides",
			"3AS_ARC_170",
		};
		units[]={
			"34thPC_ARC_170_Imperial",
		};
	};
};

class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplatePassiveRadar;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateLaser;
class SensorTemplateNV;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class CfgVehicles
{
	class Components;
	class 3AS_ARC_170_Base;
	class 34thPC_ARC_170_Base : 3AS_ARC_170_Base
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] ARC-170 Base";
		crew="3AS_Imperial_TIE_Pilot_F";
		faction="34thPC_FactionPhantom_Faction";
		class TextureSources
		{
			class Imperial
			{
				displayName="Imperial";
				author="34thPC Mod Dev Team";
				textures[]=
				{
					"overrides\data\3as\arc170\textures\Main_Frame_CO.paa",
					"overrides\data\3as\arc170\textures\Wings_Engines_CO.paa",
					"overrides\data\3as\arc170\textures\Guns_CO.paa"
				};
				factions[]=
				{
					"34thPC_FactionPhantom_Faction"
				};
			};
		};
		textureList[]=
		{
			"Republic",
			1,
			"Blue",
			0,
			"Green",
			0,
			"Orange",
			0,
			"Yellow",
			0,
			"Imperial",
			0,
		};
		class Components: Components
		{
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
						typeRecognitionDistance=4000;
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
					class LaserSensorComponent: SensorTemplateLaser
					{
					};
					class NVSensorComponent: SensorTemplateNV
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={16000,8000,4000,2000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={16000,8000,4000,2000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture="3as\3AS_ARC170\data\ui\pylon_arc.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"B_AGM65_DUAL",
							"B_AGM65_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_ASRAAM",
							"B_BIM9X",
							"B_BIM9X_DUAL_RAIL",
							"B_BIM9X_RAIL",
							"B_BOMB_PYLON",
							"B_HARM_RAIL",
							"B_SDB_QUAD_RAIL",
							"B_SHIEKER",
							"B_ZEPHYR",
							"O_BOMB_PYLON",
							"O_BOMB_PYLON_HELI",
							"O_KAB250_BOMB",
							"O_MISSILE_PYLON",
							"O_R73",
							"O_R77",
							"O_SKYFIRE",
							"SCALPEL_1RND",
							"UNI_SCALPEL",
							"REP_AGM_RAIL",
							"IMP_AGM_RAIL",
							"REP_AAA_RAIL",
							"IMP_AAA_RAIL",
							"REP_BOMB_RAIL",
						};
						attachment="PylonMissile_Bomb_KAB250_x1";
						priority=10;
						maxweight=300;
						UIposition[]={0.5,0.25};
					};
					class pylons2: pylons1
					{
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=1;
					};
					class pylons3: pylons1
					{
						hardpoints[]=
						{
							"B_AGM65_DUAL",
							"B_AGM65_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_ASRAAM",
							"B_BIM9X",
							"B_BIM9X_DUAL_RAIL",
							"B_BIM9X_RAIL",
							"B_HARM_RAIL",
							"B_MISSILE_PYLON",
							"B_SDB_QUAD_RAIL",
							"B_SHIEKER",
							"B_ZEPHYR",
							"O_KAB250_BOMB",
							"O_KH25",
							"O_KH58",
							"O_MISSILE_PYLON",
							"O_R73",
							"O_R77",
							"O_SKYFIRE",
							"SCALPEL_1RND",
							"UNI_SCALPEL",
							"REP_AGM_RAIL",
							"IMP_AGM_RAIL",
							"REP_AAA_RAIL",
							"IMP_AAA_RAIL",
							"REP_BOMB_RAIL",
						};
						attachment="PylonRack_Missile_AMRAAM_D_x2";
						priority=9;
						maxweight=2500;
						UIposition[]={0.55000001,0.34999999};
					};
					class pylons4: pylons3
					{
						UIposition[]={0.1,0.34999999};
						mirroredMissilePos=3;
					};
					class pylons5: pylons1
					{
						hardpoints[]=
						{
							"B_AGM65_DUAL",
							"B_AGM65_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_ASRAAM",
							"B_BIM9X",
							"B_BIM9X_DUAL_RAIL",
							"B_BIM9X_RAIL",
							"B_HARM_RAIL",
							"B_MISSILE_PYLON",
							"B_SDB_QUAD_RAIL",
							"B_SHIEKER",
							"B_ZEPHYR",
							"O_KH25",
							"O_KH58",
							"O_MISSILE_PYLON",
							"O_R73",
							"O_R77",
							"O_SKYFIRE",
							"SCALPEL_1RND",
							"UNI_SCALPEL",
							"REP_AGM_RAIL",
							"IMP_AGM_RAIL",
							"REP_AAA_RAIL",
							"IMP_AAA_RAIL",
							"REP_BOMB_RAIL",
						};
						attachment="PylonRack_Missile_AMRAAM_D_x2";
						priority=7;
						maxweight=5000;
						UIposition[]={0.60000002,0.44999999};
					};
					class pylons6: pylons5
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=5;
					};
				};
				class presets
				{
					class empty
					{
						displayName="$STR_empty";
						attachment[]={};
					};
					class AA
					{
						displayName="$STR_A3_cfgmagazines_titan_aa_dns";
						attachment[]=
						{
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2"
						};
					};
					class CAS
					{
						displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[]=
						{
							"PylonMissile_Bomb_KAB250_x1",
							"PylonMissile_Bomb_KAB250_x1",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2",
							"PylonRack_Missile_AMRAAM_D_x2"
						};
					};
				};
			};
		};
	};
	class 34thPC_ARC_170_Imperial : 34thPC_ARC_170_Base
	{
		author="34thPC Mod Dev Team";
		displayName="[34th] ARC-170 (Imperial)";
		scope=2;
		scopeArsenal=2;
		scopeCurator=2;
		crew="3AS_Imperial_TIE_Pilot_F";
		side=1;
		faction="34thPC_FactionPhantom_Faction";
		hiddenselectionstextures[]=
		{
			"\z\34thpc\addons\overrides\data\3as\arc170\textures\Imperial_Main_Frame_CO.paa",
			"\z\34thpc\addons\overrides\data\3as\arc170\textures\Imperial_Wings_Engines_CO.paa",
			"\z\34thpc\addons\overrides\data\3as\arc170\textures\Imperial_Glass_CO.paa",
			"\z\34thpc\addons\overrides\data\3as\arc170\textures\Imperial_Guns_CO.paa"
		};
		textureList[]=
		{
			"Republic",
			0,
			"Blue",
			0,
			"Green",
			0,
			"Orange",
			0,
			"Yellow",
			0,
			"Imperial",
			1,
		};
	};
};
