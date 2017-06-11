/// @file Textures.h
/// @brief Texture loading
/// @author Ivan Fonseca

#ifndef _INC_TEXTURES_H
#define _INC_TEXTURES_H

#include <allegro5/allegro.h>

/// @brief Loads textures into an array
/// @param path Path to folder in which textures are located (must end with a "/")
/// @param textures The array to load textures into
/// @return 0 on error, 1 otherwise
int loadTextures(const char *path, ALLEGRO_BITMAP *textures[]);

#endif
