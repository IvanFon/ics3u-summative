/// @file LevelSelect.h
/// @brief Level selection screen
/// @author Ivan Fonseca

#ifndef _INC_LEVELSELECT_H
#define _INC_LEVELSELECT_H

#include <allegro5/allegro.h>

/// @brief Gets all user levels
/// @return Array of user levels
void getUserLevels(char *arr[]);

/// @brief Draws the level select screen
void showLevelSelect();

#endif
