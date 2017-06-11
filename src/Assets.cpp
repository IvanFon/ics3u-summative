/// @file Assets.cpp
/// @brief Loads assets
/// @author Ivan Fonseca

#include "../inc/Assets.h"

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include "../inc/Level.h"
#include "../inc/Constants.h"
#include "../inc/Sprite.h"
#include "../inc/Init.h"
#include "../inc/Textures.h"
#include "../inc/Text.h"
#include "../inc/Utils.h"
#include "../inc/LevelSelect.h"

Level levels[NUM_LEVELS];
ALLEGRO_BITMAP *textures[NUM_TEXTURES];

Sprite menuSprites[NUM_MENU_SPRITES];
Sprite menuSpritesHover[NUM_MENU_SPRITES];
Sprite settingsBackSprite[2];
Sprite lvlSelectBackSprite[2];
Sprite player;

int loadAssets() {
    // Display asset loading screen
    al_draw_bitmap(loadingAssets, 0, 0, 0);
    al_flip_display();

    if (!loadLevels((char *)LVL_FOLDER, levels)) {
        fprintf(stderr, "Error loading levels!\n");
        return 0;
    }

    if (!loadTextures(TEXTURE_FOLDER, textures)) {
        fprintf(stderr, "Error loading textures!\n");
        return 0;
    }

    if (!loadFonts()) {
        fprintf(stderr, "Error loading fonts!\n");
        return 0;
    }

    // Load menu sprites
    for (int i = 0; i < NUM_MENU_SPRITES; i++) {
        // Normal menu sprite
        // Load texture
        menuSprites[i].texture = al_load_bitmap(MENU_SPRITE_PATHS[i]);
        if (!menuSprites[i].texture) {
            fprintf(stderr, "Error loading menu sprites!\n");
            return 0;
        }

        // Get size
        menuSprites[i].rect.size = {
            (float) al_get_bitmap_width(menuSprites[i].texture), (float) al_get_bitmap_height(menuSprites[i].texture)
        };

        // Get position
        menuSprites[i].rect.pos = MENU_SPRITE_POS[i];

        // Hovered menu sprite
        // Load texture
        menuSpritesHover[i].texture = al_load_bitmap(MENU_SPRITE_HOVER_PATHS[i]);
        if (!menuSpritesHover[i].texture) {
            fprintf(stderr, "Error loading hovered menu sprites!\n");
        }

        // Get size
        menuSpritesHover[i].rect.size = {
            (float) al_get_bitmap_width(menuSpritesHover[i].texture),
            (float) al_get_bitmap_height(menuSpritesHover[i].texture)
        };

        // Get position
        menuSpritesHover[i].rect.pos = MENU_SPRITE_POS[i];
    }

    // Settings back button
    settingsBackSprite[0].texture = al_load_bitmap(SETTINGS_BACK_PATH);
    settingsBackSprite[1].texture = al_load_bitmap(SETTINGS_BACK_HOVER_PATH);
    lvlSelectBackSprite[0].texture = al_load_bitmap(SETTINGS_BACK_PATH);
    lvlSelectBackSprite[1].texture = al_load_bitmap(SETTINGS_BACK_HOVER_PATH);
    if (!settingsBackSprite[0].texture || !settingsBackSprite[1].texture || !lvlSelectBackSprite[0].texture || !lvlSelectBackSprite[1].texture) {
        fprintf(stderr, "Error loading settings back button sprite!\n");
    }

    for (int i = 0; i < 2; i++) {
        settingsBackSprite[i].rect = SETTINGS[SETTING_BACK];
    }
    for (int i = 0; i < 2; i++) {
        lvlSelectBackSprite[i].rect.pos = LVL_SELECT_BACK_POS;
        lvlSelectBackSprite[i].rect.size = {
             (float) al_get_bitmap_width(lvlSelectBackSprite[i].texture),
             (float) al_get_bitmap_height(lvlSelectBackSprite[i].texture)
        };
    }

    // Player texture
    player.texture = al_load_bitmap(PLAYER_PATH);
    if (!player.texture) {
        fprintf(stderr, "Error loading player sprite!\n");
        return 0;
    }

    // Player size
    player.rect.size = {
        (float) al_get_bitmap_width(player.texture),
        (float) al_get_bitmap_height(player.texture)
    };

    //char *lvls[100] = { NULL };
    //getUserLevels(lvls);

    //for (int i = 0; lvls[i]; i++) {
        //printf("Level %d: %s\n", i, lvls[i]);
    //}

    return 1;
}
