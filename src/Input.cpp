/// @file Input.h
/// @brief Handles input
/// @author Ivan Fonseca

#include "../inc/Input.h"

#include <allegro5/allegro.h>

Input input;

void updateInput(ALLEGRO_EVENT event, KEY_STATE state) {
    // !! is used to convert an int to bool
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
            input.escape = !!state;
            break;
        case ALLEGRO_KEY_LEFT:
        case ALLEGRO_KEY_A:
            input.left = !!state;
            break;
        case ALLEGRO_KEY_DOWN:
        case ALLEGRO_KEY_S:
            input.down = !!state;
            break;
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_W:
            input.up = !!state;
            break;
        case ALLEGRO_KEY_RIGHT:
        case ALLEGRO_KEY_D:
            input.right = !!state;
            break;
        case ALLEGRO_KEY_SPACE:
            input.space = !!state;
            break;
    }
}
