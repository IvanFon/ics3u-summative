/// @file States.h
/// @brief Finite-state machine
/// @author Ivan Fonseca

/// @brief Add attack state

#ifndef _INC_STATES_H
#define _INC_STATES_H

#include <math.h>

/// @brief State function type
typedef void (*StateFunc)();

/// @brief A state
struct State {
    StateFunc function;
};

/// @brief Current player state
extern State playerState;

/// @brief Player walking state
void playerStateWalking();

/// @brief Player jumping state
void playerStateJumping();

/// @brief Runs the current player state
void runState();

#endif
