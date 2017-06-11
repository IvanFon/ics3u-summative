/// @file States.cpp
/// @brief Finite-state machine
/// @author Ivan Fonseca

#include "../inc/States.h"

#include <math.h>

#include "../inc/Utils.h"
#include "../inc/Player.h"
#include "../inc/Input.h"
#include "../inc/Constants.h"

State playerState;

void playerStateWalking() {
    // Handle jump input
    if (input.up) {
        // Switch to jump state
        playerState = { playerStateJumping };
        // Begin jumping
        playerVel.y = PLAYER_ACCEL_Y;
    }

    // Move
    move(false);
}

void playerStateJumping() {
    // Move
    move(true);
}

void runState() {
    // Set initial state
    if (playerState.function == NULL) {
        playerState = { playerStateWalking };
    }
    // Run current state
    playerState.function();
}