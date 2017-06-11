/// @file Settings.h
/// @brief Deals with loading and saving settings
/// @author Ivan Fonseca

#ifndef _INC_SETTINGS_H
#define _INC_SETTINGS_H

#include <allegro5/allegro.h>

/// @brief Game settings
extern ALLEGRO_CONFIG *config;

/// @brief Gets a setting fron the config file as an integer
/// @param section Section where the key is located
/// @param key Key for the value to fetch
/// @return The value as an integer
int getSetting(const char *section, const char *key);

/// @brief Sets a setting in a config file
/// @param path The path to the config file
/// @param section Section where the key is located
/// @param key Key for the value to set
/// @param value Value to set the key to
/// @return 0 on error, 1 otherwise
int setSetting(const char *path, const char *section, const char *key, int value);

/// @brief Draws the settings menu
void drawSettings();

#endif
