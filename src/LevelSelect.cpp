/// @file LevelSelect.cpp
/// @brief Level selection screen
/// @author Ivan Fonseca

#include "../inc/LevelSelect.h"

#include <stdlib.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include "../inc/Quit.h"
#include "../inc/Utils.h"
#include "../inc/Physics.h"
#include "../inc/Init.h"
#include "../inc/Constants.h"
#include "../inc/Assets.h"
#include "../inc/Text.h"
#include "../inc/Game.h"
#include "../inc/Level.h"

bool campaign = false;
Level usrLvl;

int pickFile(char *str, int size) {
    // Create a file picker
    ALLEGRO_FILECHOOSER *dialog = al_create_native_file_dialog("./assets/levels/user/.", "Open a level", "*.*", ALLEGRO_FILECHOOSER_FILE_MUST_EXIST);
    if (!dialog) {
        fprintf(stderr, "Error opening file picker!\n");
        al_destroy_native_file_dialog(dialog);
        return 0;
    }

    al_show_native_file_dialog(display, dialog);
    if (al_get_native_file_dialog_count(dialog) > 0) {
        snprintf(str, size, "%s", (char *) al_get_native_file_dialog_path(dialog, 0));
    } else {
        al_destroy_native_file_dialog(dialog);
        return 0;
    }
    al_destroy_native_file_dialog(dialog);

    return 1;
}

void showLevelSelect() {
    bool redraw = false;
    bool mouseDown = false;
    bool hover[3] = { false };
    bool backHover = false;
    Sprite playSprites[] = {
        lvlSelectCampaignSprite[0],
        lvlSelectChooseSprite[0],
        lvlSelectEditorSprite[0],
        lvlSelectBackSprite[0]
    };
    Sprite playSpritesHover[] = {
        lvlSelectCampaignSprite[1],
        lvlSelectChooseSprite[1],
        lvlSelectEditorSprite[1],
        lvlSelectBackSprite[1]
    };
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

        // Check if cursor is touching back button
        for (int i = 0; i < 4; i++) {
            if (pointRect(mouse, playSprites[i].rect)) {
                if (mouseDown) {
                    char usrPath[100];
                    switch (i) {
                        case PLAY_CAMPAIGN:
                            campaign = true;
                            gameLoop();
                            break;
                        case PLAY_CHOOSE:
                            if (pickFile(usrPath, 100)) {
                                // Load this level
                                if (loadLevel(usrPath, usrLvl)) {
                                    campaign = false;
                                    gameLoop();
                                } else {
                                    fprintf(stderr, "Error loading user level \"%s\"!\n", usrPath);
                                }
                            }
                            break;
                        case PLAY_EDITOR:
                            // Open the editor in web browser
                            #ifdef _WIN32
                                system("start \"\" editor/index.html");
                            #else
                                system("xdg-open editor/index.html");
                            #endif
                            break;
                        case PLAY_BACK:
                            return;
                            break;
                    }
                } else {
                    hover[i] = true;
                }
            } else {
                hover[i] = false;
            }
        }

        // Reset mouse
        mouseDown = false;

        // Draw
        if (redraw && al_is_event_queue_empty(evQueue)) {
            redraw = false;
            al_clear_to_color(COL_BLACK);

            // Draw buttons
            for (int i = 0; i < 4; i++) {
                drawSprite(
                    (hover[i]) ?
                    playSpritesHover[i] :
                    playSprites[i]);
            }

            al_flip_display();
        }
    }
}
