/// @file LevelSelect.cpp
/// @brief Level selection screen
/// @author Ivan Fonseca

#include "../inc/LevelSelect.h"

#include <stdlib.h>
#include <stdio.h>

#include <allegro5/allegro.h>

#include "../inc/Quit.h"
#include "../inc/Utils.h"
#include "../inc/Physics.h"
#include "../inc/Init.h"
#include "../inc/Constants.h"
#include "../inc/Assets.h"

void getUserLevels(char *arr[]) {
    // Open user level directory
    ALLEGRO_FS_ENTRY *dir = al_create_fs_entry("assets/levels/user/");
    if (!al_open_directory(dir)) {
        fprintf(stderr, "Error creating user level directory entry!\n");
        quitGame();
    }
    
    // Loop through levels
    ALLEGRO_FS_ENTRY *file;
    for (int i = 0; file = al_read_directory(dir); i++) {
        // Get filename only and add it to the array
        arr[i] = (char *) getFilename(al_get_fs_entry_name(file));
        al_destroy_fs_entry(file);
    }

    al_destroy_fs_entry(dir);
}

void showLevelSelect() {
    bool redraw = false;
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
                // Check if left button
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

        // Check if cursor is touching button
        for (int i = 0; i < 1; i++) {
            if (pointRect(mouse, lvlSelectBackSprite[0].rect)) {
                if (mouseDown) {
                    switch (i) {
                        // Back button
                        case 0:
                            return;
                            break;
                    }
                } else {
                    if (i == 0) {
                        backHover = true;
                    }
                }
            } else {
                if (i == 0) {
                    backHover = false;
                }
            }
        }

        // Reset mouse
        mouseDown = false;

        // Draw
        if (redraw && al_is_event_queue_empty(evQueue)) {
            redraw = false;
            al_clear_to_color(COL_BLACK);

            // Draw back button
            drawSprite((backHover) ? lvlSelectBackSprite[1] : lvlSelectBackSprite[0]);

            al_flip_display();
        }
    }
}
