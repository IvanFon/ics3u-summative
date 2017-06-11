/// @file Game.h
/// @brief Main game loop
/// @author Ivan Fonseca

#ifndef _INC_GAME_H
#define _INC_GAME_H

/// @brief Current level
extern int curLvl;
/// @brief If the current level has finished loading
extern bool levelLoaded;

/// @brief Main game loop
void gameLoop();

#endif
