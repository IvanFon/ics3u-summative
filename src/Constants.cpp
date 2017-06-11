/// @file Constants.cpp

/// @author Ivan Fonseca

#include "../inc/Constants.h"

#include "../inc/Physics.h"

// RESOURCES

const char *TEXTURE_FOLDER = "assets/tiles/";

const char *LVL_FOLDER = (char *)"assets/levels/campaign/";

const char *MENU_SPRITE_PATHS[] = {
    "assets/sprites/menu/play.png",
    "assets/sprites/menu/settings.png",
    "assets/sprites/menu/exit.png"
};
const char *MENU_SPRITE_HOVER_PATHS[] = {
    "assets/sprites/menu/play-down.png",
    "assets/sprites/menu/settings-down.png",
    "assets/sprites/menu/exit-down.png"
};
const Vector MENU_SPRITE_POS[] = {
    { 155.5, 140.0 },
    { 155.5, 250.0 },
    { 332.6, 250.0 }
};

/// @todo fix this
const Rectangle SETTINGS[] = {
    {
        { 275, 85 },
        { 90, 60 }
    },
    {
        { 275, 180 },
        { 90, 60 }
    },
    {
        { 244.5, 300 },
        { 151, 67 }
    }
};
const char *SETTINGS_BACK_PATH = "assets/sprites/back.png";
const char *SETTINGS_BACK_HOVER_PATH = "assets/sprites/back-down.png";

const char *LVL_SELECT_CAMPAIGN_PATH = "assets/sprites/campaign.png";
const char *LVL_SELECT_CAMPAIGN_HOVER_PATH = "assets/sprites/campaign-down.png";
const char *LVL_SELECT_CHOOSE_PATH = "assets/sprites/choose.png";
const char *LVL_SELECT_CHOOSE_HOVER_PATH = "assets/sprites/choose-down.png";

const Vector PLAY[] = {
    { 155.5, 140.0 },
    { 332.6, 140.0 },
    { 244.5, 250.0 }
};

const char *SETTINGS_PATH = "assets/settings.ini";

const char *MENUBG_PATH = "assets/backgrounds/menu.png";

const char *LOADING_PATHS[] = {
    "assets/backgrounds/loading-assets.png",
    "assets/backgrounds/loading-allegro.png"
};

const char *PLAYER_PATH = "assets/sprites/player.png";

const char *FONT_PATHS[] = {
    "assets/fonts/Roboto-Regular.ttf"
};

// OTHER

const Vector PLAYER_DIMENSIONS = { 16, 32 };

const Vector SCREEN = { 640, 480 };

const int SOLID_TILES[] = { 0, 2 };
