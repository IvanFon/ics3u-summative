/// @file Player.h
/// @brief Player-specific functions
/// @author Ivan Fonseca

#ifndef _INC_PLAYER_H
#define _INC_PLAYER_H

#include "Physics.h"

/// @brief Player velocity
extern Vector playerVel;

/// @brief Handles collisions
/// @param xAxis If the collision is on the X axis (Y axis otherwise)
void handleCollisions(bool xAxis /*= true*/);

/// @brief Handles horizontal movement
/// @param jumping \p true if the player is jumping, \p false otherwise
void horizontalMove(bool jumping /*= false*/);

/// @brief Handles vertical movement
void verticalMove();

/// @brief Handles both horizontal and vertical movement
/// @param jumping \p true if the player is jumping, \p false otherwise
void move(bool jumping);

#endif