#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {"ACE_Box_Misc", "ACE_bananaItem"};
        weapons[] = {"ACE_ItemCore","ACE_FakePrimaryWeapon", "ACE_Banana"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_main"};
        author[] = {"KoffeinFlummi"};
        authorUrl = "https://github.com/KoffeinFlummi/";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"

#include "CfgActions.hpp"
#include "CfgMoves.hpp"
#include "CfgVoice.hpp"

class ACE_Rsc_Display_Base {
    idd = -1;
    type = 0;
    style = 48;
    name = "";
    duration = 999999;
    fadeIn = 0;
    fadeOut = 0;
    font = "TahomaB";
    size = 1;
    colorBackground[] = {1, 1, 1, 0};
    colorText[] = {1, 1, 1, 1};
};

class ACE_Rsc_Control_Base {
    idc = 1;
    type = 0;
    style = 48;
    access = 0;
    lineSpacing = 0;
    moving = 1;
    text = "";
    size = 1;
    sizeEx = 0;
    font = "TahomaB";
    colorBackground[] = {1, 1, 1, 0};
    colorText[] = {1, 1, 1, 1};
    x = 0;
    y = 0;
    w = 0;
    h = 0;
};

class ACE_Settings {
    /*
    *class GVAR(sampleSetting) {
    * Value
    *    value = 1;
    *
    * Type (SCALAR, BOOL, STRING, ARRAY, COLOR)
    *    typeName = "SCALAR";
    *
    * Force the setting?
    *    force = 0;
    *
    * Does it appear on the options menu?
    *    isClientSetable = 1;
    *
    * The following settings only apply when isClientSetable == 1
    * Stringtable entry with the setting name
    *    displayName = "$STR_ACE_Common_SettingName";
    *
    * Stringtable entry with the setting description
    *    description = "$STR_ACE_Common_SettingDescription";
    *
    * Stringtable entries that describe the options
    * Only applies if typeName == "SCALAR";
    *    values[] = {"Disabled", "Enabled", "Only Cursor", "Only On Keypress", "Only Cursor and KeyPress"};
    *};
    */
    class GVAR(forceAllSettings) {
        value = 0;
        typeName = "BOOL";
    };
    /*class GVAR(enableNumberHotkeys) {
        value = 1;
        typeName = "BOOL";
        isClientSetable = 1;
        displayName = "$STR_ACE_Common_EnableNumberHotkeys";
    };*/
    class GVAR(settingFeedbackIcons) {
        value = 1;
        typeName = "SCALAR";
        force = 0;
        isClientSetable = 1;
        displayName = "$STR_ACE_Common_SettingFeedbackIconsName";
        description = "$STR_ACE_Common_SettingFeedbackIconsDesc";
        values[] = {"Hide", "Top right, downwards", "Top right, to the left", "Top left, downwards", "Top left, to the right"};
    };
    class GVAR(SettingProgressBarLocation) {
        value = 0;
        typeName = "SCALAR";
        force = 0;
        isClientSetable = 1;
        displayName = "$STR_ACE_Common_SettingProgressbarLocationName";
        description = "$STR_ACE_Common_SettingProgressbarLocationDesc";
        values[] = {"Top", "Bottom"};
    };
    class GVAR(displayTextColor) {
        value[] = {0,0,0,0.1};
        typeName = "COLOR";
        isClientSetable = 1;
        displayName = "$STR_ACE_Common_SettingDisplayTextColorName";
        description = "$STR_ACE_Common_SettingDisplayTextColorDesc";
    };
    class GVAR(displayTextFontColor) {
        value[] = {1,1,1,1};
        typeName = "COLOR";
        isClientSetable = 1;
        displayName = "$STR_ACE_Common_SettingDisplayTextFontColorName";
        description = "$STR_ACE_Common_SettingDisplayTextFontColorDesc";
    };
};

#include "define.hpp"
#include <ProgressScreen.hpp>
#include <HintConfig.hpp>
#include <RscInfoType.hpp>

class CfgUIGrids {
    class IGUI {
        class Presets {
            class Arma3 {
                class Variables {
                    grid_ACE_displayText[] = {{((safezoneX + safezoneW) - (10 *(((safezoneW / safezoneH) min 1.2) / 40)) - 2.9 *(((safezoneW / safezoneH) min 1.2) / 40)),safeZoneY + 0.175 * safezoneH, (10 *(((safezoneW / safezoneH) min 1.2) / 40)), (2 *((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))}, "(((safezoneW / safezoneH) min 1.2) / 40)","((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)"};
                };
            };
        };

        class Variables {
            class grid_ACE_displayText {
                displayName = "ACE Hint";
                description = "Textual in game feedback to the player.";
                preview = "\a3\Ui_f\data\GUI\Cfg\UIGrids\grid_hint_ca.paa";
                saveToProfile[] = {0,1};                
            };
        };
    };
};
