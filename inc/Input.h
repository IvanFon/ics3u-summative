/// @file Input.h
/// @brief Handles input
/// @author Ivan Fonseca

#ifndef _INC_INPUT_H
#define _INC_INPUT_H

#include <allegro5/allegro.h>

/// @brief Whether a key is up or down
enum KEY_STATE {
    /// @brief Key is up
    KEY_UP = 0,
    /// @brief Key is down
    KEY_DOWN
};

/// @brief Stores input data
struct Input {
    /// @brief Escape key
    bool escape;
    /// @brief Left arrow key
    bool left;
    /// @brief Down arrow key
    bool down;
    /// @brief Up arrow key
    bool up;
    /// @brief Right arrow key
    bool right;
    /// @brief Spacebar
    bool space;
};

/// @brief Current input
extern Input input;

/// @brief Updates Input
/// @param event The ALLEGRO_EVENT containing keyboard changes
/// @param state Whether the key was pressed or released
void updateInput(ALLEGRO_EVENT event, KEY_STATE state);

#endif
