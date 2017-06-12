/// @file Menu.cpp
/// @brief Menu screen
/// @author Ivan Fonseca

#include "../inc/Menu.h"

#include <stdio.h>

#include <allegro5/allegro.h>

#include "../inc/Init.h"
#include "../inc/Assets.h"
#include "../inc/Settings.h"
#include "../inc/Quit.h"
#include "../inc/Game.h"
#include "../inc/Sprite.h"
#include "../inc/Constants.h"
#include "../inc/LevelSelect.h"
#include "../inc/Instructions.h"

void showMenu() {
    // Menu loop

    bool redraw = true;
    bool mouseDown = false;
    bool menuHover[NUM_MENU_SPRITES] = { false };

    al_clear_to_color(COL_BLACK);

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
        } // \switch

        // Check if cursor intersects a button
        for (int i = 0; i < NUM_MENU_SPRITES; i++) {
            if (pointRect(mouse, menuSprites[i].rect)) {
                if (mouseDown) {
                    switch (i) {
                        case MENU_PLAY:
                            al_stop_timer(timer);
                            showLevelSelect();
                            break;
                        case MENU_SETTINGS:
                            al_stop_timer(timer);
                            drawSettings();
                            break;
                        case MENU_EXIT:
                            quitGame();
                            break;
                        case MENU_HOWTO:
                            showIntructions();
                            break;
                    }
                } else {
                    menuHover[i] = true;
                }
            } else {
                menuHover[i] = false;
            }
        }

        // Reset mouse
        mouseDown = false;

        // Draw
        if (redraw && al_is_event_queue_empty(evQueue)) {
            al_clear_to_color(COL_BLACK);
            // Draw buttons (sprite changes if mouse is hovering over button)
            for (int i = 0; i < NUM_MENU_SPRITES; i++) {
                drawSprite(
                    (menuHover[i]) ?
                    menuSpritesHover[i] :
                    menuSprites[i]);
            }
            al_flip_display();
        }
    }
}
