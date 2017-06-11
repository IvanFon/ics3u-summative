/// @file Init.cpp
/// @brief Initializes Allegro
/// @author Ivan Fonseca

#include "../inc/Init.h"

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "../inc/Constants.h"
#include "../inc/Settings.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *evQueue;
ALLEGRO_TIMER *timer;

// Loading screens
ALLEGRO_BITMAP *loadingAllegro;
ALLEGRO_BITMAP *loadingAssets;

int init() {
    // Load config before initialization
    config = al_load_config_file(SETTINGS_PATH);
    
    // Initialize Allegro & addons

    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return 0;
    }
    
    if (!al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize image addon!\n");
        return 0;
    }

    if (!al_install_keyboard()) {
        fprintf(stderr, "Failed to install keyboard!\n");
        return 0;
    }

    if (!al_install_mouse()) {
        fprintf(stderr, "Failed to install mouse!\n");
        return 0;
    }

    if (!al_init_font_addon()) {
        fprintf(stderr, "Failed to initialize font addon!\n");
        return 0;
    }

    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize TTF addon!\n");
        return 0;
    }

    // Set fullscreen
    if (strcmp(al_get_config_value(config, "video", "fullscreen"), "1") == 0) {
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    }

    // Create display
    display = al_create_display(SCREEN.x, SCREEN.y);
    if (!display) {
        fprintf(stderr, "Failed to create display!\n");
        return 0;
    }
    // Set window title
    al_set_window_title(display, "Ivan ICS3U Summative");

    // Load loading screens
    loadingAllegro = al_load_bitmap(LOADING_PATHS[0]);
    loadingAssets = al_load_bitmap(LOADING_PATHS[1]);
    if (!loadingAllegro || !loadingAssets) {
        fprintf(stderr, "Failed to load loading screens!\n");
        return 0;
    }

    // Display loading screen
    al_draw_bitmap(loadingAllegro, 0, 0, 0);
    al_flip_display();

    evQueue = al_create_event_queue();
    if (!evQueue) {
        fprintf(stderr, "Failed to create event queue!\n");
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "Failed to create timer!\n");
        return 0;
    }

    // Register event sources
    al_register_event_source(evQueue, al_get_display_event_source(display));
    al_register_event_source(evQueue, al_get_timer_event_source(timer));
    al_register_event_source(evQueue, al_get_keyboard_event_source());
    al_register_event_source(evQueue, al_get_mouse_event_source());

    return 1;
}
