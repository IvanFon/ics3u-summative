/// @file Constants.h
/// @brief Some constant values to avoid repitition
/// @author Ivan Fonseca

#ifndef _INC_CONSTANTS_H
#define _INC_CONSTANTS_H

#include "Physics.h"

// DEFINES

// Defining ALLEGRO_COLOR constants was buggy on different
// platforms, so preprocessor directives are being used instead
/// @brief White
#define COL_WHITE al_map_rgb(255, 255, 255)
/// @brief Black
#define COL_BLACK al_map_rgb(0, 0, 0)

// RESOURCES

/// @brief Number of textures to read
const int NUM_TEXTURES = 3;
/// @brief Texture folder
extern const char *TEXTURE_FOLDER;

/// @brief Number of levels to load
const int NUM_LEVELS = 6;
/// @brief Level folder
extern const char *LVL_FOLDER;

/// @brief Menu sprites
enum MENU_SPRITES {
    MENU_PLAY = 0,
    MENU_SETTINGS,
    MENU_EXIT,
    MENU_HOWTO
};
/// @brief Number of menu sprites
const int NUM_MENU_SPRITES = 4;
/// @brief Menu sprite paths
extern const char *MENU_SPRITE_PATHS[];
/// @brief Hovered menu sprite paths
extern const char *MENU_SPRITE_HOVER_PATHS[];
/// @brief Menu sprite positions
extern const Vector MENU_SPRITE_POS[];

/// @brief Settings names
enum SETTINGS_NAMES {
    SETTING_FULLSCREEN = 0,
    SETTING_AUDIO,
    SETTING_BACK
};
/// @brief Number of settings
const int NUM_SETTINGS = 3;
/// @brief Settings positions
extern const Rectangle SETTINGS[];
/// @brief Settings back button sprite
extern const char *SETTINGS_BACK_PATH;
/// @brief Settings back button hoverer sprite
extern const char *SETTINGS_BACK_HOVER_PATH;

/// @brief Campaign button sprite path
extern const char *LVL_SELECT_CAMPAIGN_PATH;
/// @brief Campaign button hover sprite path
extern const char *LVL_SELECT_CAMPAIGN_HOVER_PATH;
/// @brief Level select button sprite path
extern const char *LVL_SELECT_CHOOSE_PATH;
/// @brief Level select button hover sprite path
extern const char *LVL_SELECT_CHOOSE_HOVER_PATH;
/// @brief Level select editor button sprite path
extern const char *LVL_SELECT_EDITOR_PATH;
/// @brief Level select editor hover sprite path
extern const char *LVL_SELECT_EDITOR_HOVER_PATH;

/// @brief Play screen buttons
enum PLAY_BUTTONS {
    PLAY_CAMPAIGN = 0,
    PLAY_CHOOSE,
    PLAY_EDITOR,
    PLAY_BACK
};
/// @brief Play screen button locations
extern const Vector PLAY[];
/// @brief Settings file
extern const char *SETTINGS_PATH;

/// @brief Menu background path
extern const char *MENUBG_PATH;

/// @brief Loading screens
extern const char *LOADING_PATHS[];

/// @brief Player sprite path
extern const char *PLAYER_PATH;

/// @brief Font names
enum FontNames {
    ROBOTOREG = 0
};
/// @brief Font paths
extern const char *FONT_PATHS[];

// PLAYER MOVEMENT

/// @brief Player's horizontal acceleration
const float PLAYER_ACCEL_X = 0.05;
/// @brief Player's horizontal decceleration
const float PLAYER_DECCEL_X = PLAYER_ACCEL_X * 2;
/// @brief Player's horizontal acceleration in the air
const float PLAYER_ACCEL_AIR_X = 0.1;
/// @brief Player's horizontal decceleration in the air
const float PLAYER_DECCEL_AIR_X = PLAYER_ACCEL_AIR_X * 2;
/// @brief Player's maximum X velocity
const float PLAYER_MAX_VEL_X = 0.1;
/// @brief Player's decceleration boost when changing direction
const float PLAYER_DECCEL_BOOST = 2;

/// @brief Player's vertical acceleration
const float PLAYER_ACCEL_Y = -4;
/// @brief Player's acceleration from gravity
const float GRAVITY_ACCEL = 0.2;

// OTHER

/// @brief Level width
const int LVL_WIDTH = 40;
/// @brief Level height
const int LVL_HEIGHT = 35;

/// @brief Tile length and height
const int TILE_WIDTH = 16;

/// @brief Player dimensions
extern const Vector PLAYER_DIMENSIONS;

/// @brief Framerate
const float FPS = 60.0;

/// @brief Screen dimensions
extern const Vector SCREEN;

/// @brief Number of solid tiles
const int NUM_SOLID_TILES = 2;
/// @brief Solid tiles
extern const int SOLID_TILES[];

#endif
