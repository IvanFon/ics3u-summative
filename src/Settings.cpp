/// @file Settings.cpp
/// @brief Deals with loading and saving settings
/// @author Ivan Fonseca

#include "../inc/Settings.h"

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "../inc/Init.h"
#include "../inc/Physics.h"
#include "../inc/Text.h"
#include "../inc/Constants.h"
#include "../inc/Quit.h"
#include "../inc/Utils.h"
#include "../inc/Assets.h"

ALLEGRO_CONFIG *config;

int getSetting(const char *section, const char *key) {
    return atoi(al_get_config_value(config, section, key));
}

int setSetting(const char *path, const char *section, const char *key, int value) {
    // Convert value to a string
    char newVal[20];
    itoa(newVal, value);
    // Modify config
    al_set_config_value(config, section, key, newVal);
    // Save config
    if (!al_save_config_file(SETTINGS_PATH, config)) {
        fprintf(stderr, "Error saving config!\n");
    }
}

void drawSettings() {
    bool redraw = true;
    bool mouseDown = false;
    bool backHover = false;
    al_start_timer(timer);
    while (true) {
        // Get events
        ALLEGRO_EVENT event;
        al_wait_for_event(evQueue, &event);

        // Get mouse state
        ALLEGRO_MOUSE_STATE mouseState;
        al_get_mouse_state(&mouseState);
        // Get mouse coordinates
        Vector mouse = {
            (float) al_get_mouse_state_axis(&mouseState, 0),
            (float) al_get_mouse_state_axis(&mouseState, 1)
        };

        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                quitGame();
                break;

            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                // Check if it was the left mouse button
                if (al_mouse_button_down(&mouseState, 1)) {
                    mouseDown = true;
                }
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    quitGame();
                }
                break;
        } // \switch

        // Check if cursor is touching a setting
        for (int i = 0; i <= NUM_SETTINGS; i++) {
            if (pointRect(mouse, SETTINGS[i])) {
                if (mouseDown) {
                    switch (i) {
                        case SETTING_FULLSCREEN:
                            if (setSetting(SETTINGS_PATH, "video", "fullscreen", !getSetting("video", "fullscreen"))) {
                                fprintf(stderr, "Error setting fullscreen setting!\n");
                            }
                            break;
                        case SETTING_AUDIO:
                            if (setSetting(SETTINGS_PATH, "audio", "on", !getSetting("audio", "on"))) {
                                fprintf(stderr, "Error setting audio setting!\n");
                            }
                            break;
                        case SETTING_BACK:
                            return;
                            break;
                    }
                } else {
                    if (i == SETTING_BACK) {
                        backHover = true;
                    }
                }
            } else {
                if (i == SETTING_BACK) {
                    backHover = false;
                }
            }
        }

        // Reset mouse
        mouseDown = false;

        // Draw settings
        if (redraw && al_is_event_queue_empty(evQueue)) {
            redraw = false;
            al_clear_to_color(COL_BLACK);
            
            // Draw back button
            drawSprite((backHover) ? settingsBackSprite[1] : settingsBackSprite[0]);

            // Draw settings
            
            // Fullscreen
            al_draw_text(fonts.robotoReg, COL_WHITE, SCREEN.x / 2, 75, ALLEGRO_ALIGN_CENTRE, "Fullscreen (requires restart):");
            al_draw_text(fonts.robotoReg, COL_WHITE, SCREEN.x / 2, 100, ALLEGRO_ALIGN_CENTRE, (getSetting("video", "fullscreen")) ? "On" : "Off");
            // Audio
            al_draw_text(fonts.robotoReg, COL_WHITE, SCREEN.x / 2, 175, ALLEGRO_ALIGN_CENTRE, "Audio:");
            al_draw_text(fonts.robotoReg, COL_WHITE, SCREEN.x / 2, 200, ALLEGRO_ALIGN_CENTRE, (getSetting("audio", "on")) ? "On" : "Off");

            al_flip_display();
        }
    }
}
