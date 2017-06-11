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
Sprite lvlSelectCampaignSprite[2];
Sprite lvlSelectChooseSprite[2];
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
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        settingsBackSprite[i].rect = SETTINGS[SETTING_BACK];
    }
    for (int i = 0; i < 2; i++) {
        lvlSelectBackSprite[i].rect.pos = PLAY[PLAY_BACK];
        lvlSelectBackSprite[i].rect.size = {
             (float) al_get_bitmap_width(lvlSelectBackSprite[i].texture),
             (float) al_get_bitmap_height(lvlSelectBackSprite[i].texture)
        };
    }

    // Level select campaign button
    lvlSelectCampaignSprite[0].texture = al_load_bitmap(LVL_SELECT_CAMPAIGN_PATH);
    lvlSelectCampaignSprite[1].texture = al_load_bitmap(LVL_SELECT_CAMPAIGN_HOVER_PATH);
    if (!lvlSelectCampaignSprite[0].texture || !lvlSelectCampaignSprite[1].texture) {
        fprintf(stderr, "Error loading campaign button sprite!\n");
        return 0;
    }
    for (int i = 0 ; i < 2; i++) {
        lvlSelectCampaignSprite[i].rect.pos = PLAY[PLAY_CAMPAIGN];
        lvlSelectCampaignSprite[i].rect.size = {
            (float) al_get_bitmap_width(lvlSelectCampaignSprite[i].texture),
            (float) al_get_bitmap_height(lvlSelectCampaignSprite[i].texture)
        };
    }

    // Level select choose button
    lvlSelectChooseSprite[0].texture = al_load_bitmap(LVL_SELECT_CHOOSE_PATH);
    lvlSelectChooseSprite[1].texture = al_load_bitmap(LVL_SELECT_CHOOSE_HOVER_PATH);
    if (!lvlSelectChooseSprite[0].texture || !lvlSelectChooseSprite[1].texture) {
        fprintf(stderr, "Error loading choose level button sprite!\n");
    }
    for (int i = 0; i < 2; i++) {
        lvlSelectChooseSprite[i].rect.pos = PLAY[PLAY_CHOOSE];
        lvlSelectChooseSprite[i].rect.size = {
            (float) al_get_bitmap_width(lvlSelectChooseSprite[i].texture),
            (float) al_get_bitmap_height(lvlSelectChooseSprite[i].texture)
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

    return 1;
}
