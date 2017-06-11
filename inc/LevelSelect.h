/// @file LevelSelect.h
/// @brief Level selection screen
/// @author Ivan Fonseca

#ifndef _INC_LEVELSELECT_H
#define _INC_LEVELSELECT_H

#include <allegro5/allegro.h>

#include "Level.h"

/// @brief If the player is in the campaign
extern bool campaign;
/// @brief Currently loaded user level
extern Level usrLvl;

/// @brief Opens a file picker and returns the chosen file
/// @brief str The path to the chosen file
/// @brief size Size of the string
/// @return 0 on error or cancel, 1 otherwise
int pickFile(char *str, int size);

/// @brief Draws the level select screen
void showLevelSelect();

#endif
