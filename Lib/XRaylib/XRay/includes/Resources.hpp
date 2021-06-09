/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Resources
*/

#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_

typedef enum {
    ADD,
    REMOVE,
    PREVIOUS,
    NEXT,
    CONTROLS,
    GAMEPAD,
    HUMAN,
    AI,
    HEAD,
    LOADGAME_BG,
    LOADGAME,
    LOADGAME_HOVER,
    NEWGAME_BG,
    NEWGAME,
    NEWGAME_HOVER,
    LOADSCENE,
    BRANCH,
    BACK,
    BACK_HOVER,
    HELP,
    HELP_HOVER,
    SETTINGS,
    SETTINGS_HOVER,
    INDIE,
    STUDIO,
    MENU_TITLE,
    BOMBER_TEAM,
    BOMBER_THINKING,
    PLAY,
    PLAY_HOVER,
    QUIT,
    QUIT_HOVER,
    SKIP,
    SKIP_HOVER,
    PARALLAX,
    BG,
    p1,
    p2,
    p3,
    p4,
    P1,
    P2,
    P3,
    P4,
    MOUSEYELLOW,
    KEYBOARDYELLOW,
    PLAYSTATIONYELLOW,
    XBOXYELLOW,
    MOUSEBLUE,
    KEYBOARDBLUE,
    PLAYSTATIONBLUE,
    XBOXBLUE,
    NEXTSCENE,
    NEXT_HOVER,
    MAPCHOICEBG,
    SIZE_HOVER,
    SETS_HOVER,
    DURATION_HOVER,
    AI_HOVER,
    SIZE,
    SETS,
    DURATION,
    IA,
    MOUSEPANEL,
    KEYBOARDPANEL,
    PLAYSTATIONPANEL,
    XBOXPANEL,
    PAUSE,
    DEPAUSE,
    PAUSEBACK,
    RESUME,
    RESTART,
    SAVE,
    SETTING,
    HOME,
    RESUMEHOVER,
    RESTARTHOVER,
    SAVEHOVER,
    SETTINGSHOVER,
    HOMEHOVER,
    SAVED,
    BACKUPBAR,
    VICTORYBG,
    DEFEATBG,
    NEXTLEVEL,
    NEXTLEVELHOVER,
    RANKING,
    UNKNOWN,
    ON,
    OFF,
    SETTING_BG,
    VOLUME_UP,
    VOLUME_DOWN
} Resources;

typedef enum {
    MSC_BOMBERMAN
} MusicResources;

typedef enum {
    SFX_KLICK,
    SFX_ENTER,
    SFX_SETTING
} SfxResources;

#endif /* !RESOURCES_HPP_ */
