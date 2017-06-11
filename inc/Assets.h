/// @file Assets.h
/// @brief Loads assets
/// @author Ivan Fonseca

#ifndef _INC_ASSETS_H
#define _INC_ASSETS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include "Level.h"
#include "Constants.h"
#include "Sprite.h"

/// @brief All Levels get loaded into this array at the start of the game
extern Level levels[NUM_LEVELS];
/// @brief All tile textures get loaded into this array at the start of the game
extern ALLEGRO_BITMAP *textures[NUM_TEXTURES];

/// @brief Menu sprites
extern Sprite menuSprites[NUM_MENU_SPRITES];
/// @brief Hovered menu sprites
extern Sprite menuSpritesHover[NUM_MENU_SPRITES];
/// @brief Settings back button sprite (0 = normal, 1 = hover)
extern Sprite settingsBackSprite[2];
/// @brief Level select back button sprite
extern Sprite lvlSelectBackSprite[2];
/// @brief Player Sprite
extern Sprite player;

/// @brief Loads assets
/// @return 0 on error, 1 otherwise
int loadAssets();

#endif
