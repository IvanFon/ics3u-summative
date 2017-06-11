/// @file Quit.cpp
/// @brief Closes the game
/// @author Ivan Fonseca

#include "../inc/Quit.h"

#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../inc/Assets.h"
#include "../inc/Init.h"
#include "../inc/Constants.h"
#include "../inc/Settings.h"

/// @brief Cleans up and closes the game
void quitGame() {
    al_destroy_timer(timer);
    al_destroy_event_queue(evQueue);
    al_destroy_display(display);
    al_destroy_bitmap(loadingAllegro);
    al_destroy_bitmap(loadingAssets);
    al_destroy_bitmap(player.texture);
    for (int i = 0; i < NUM_TEXTURES; i++) {
        al_destroy_bitmap(textures[i]);
    }
    for (int i = 0; i < 2; i++) {
        al_destroy_bitmap(settingsBackSprite[i].texture);
        al_destroy_bitmap(lvlSelectBackSprite[i].texture);
        al_destroy_bitmap(lvlSelectCampaignSprite[i].texture);
        al_destroy_bitmap(lvlSelectChooseSprite[i].texture);
    }
    for (int i = 0; i < NUM_MENU_SPRITES; i++) {
        al_destroy_bitmap(menuSprites[i].texture);
        al_destroy_bitmap(menuSpritesHover[i].texture);
    }
    al_destroy_config(config);
    exit(1);
}
