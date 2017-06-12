/// @file Instructions.cpp
/// @brief Instructions screen
/// @author Ivan Fonseca

#include <allegro5/allegro.h>

#include "../inc/Init.h"
#include "../inc/Physics.h"
#include "../inc/Quit.h"
#include "../inc/Assets.h"
#include "../inc/Text.h"

void showIntructions() {
    bool redraw = true;
    bool backHover = false;
    bool mouseDown = false;
    // Text to draw
    const char *text[] = {
        "You are the red cube.",
        "You can move with WASD or the arrow keys.",
        "Your goal is to reach the orange cube.",
        "If you fall off a platform, you may jump once in midair.",
        "Good luck!"
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

        // Check if touching back
        if (pointRect(mouse, settingsBackSprite[0].rect)) {
            if (mouseDown) {
                return;
            } else {
                backHover = true;
            }
        } else {
            backHover = false;
        }

        // Reset mouse
        mouseDown = false;

        // Draw instructions
        if (redraw && al_is_event_queue_empty(evQueue)) {
            redraw = false;
            al_clear_to_color(COL_BLACK);

            // Draw back button
            drawSprite((backHover) ? settingsBackSprite[1] : settingsBackSprite[0]);

            // Draw instructions
            for (int i = 0; i < 5; i++) {
                al_draw_text(fonts.robotoReg, COL_WHITE, SCREEN.x / 2, (i * 25) + 125, ALLEGRO_ALIGN_CENTRE, text[i]);
            }

            al_flip_display();
        }
    }
}
