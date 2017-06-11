/// @file Texture.cpp
/// @brief Texture loading
/// @author Ivan Fonseca

#include "../inc/Textures.h"

#include <stdio.h>

#include <allegro5/allegro.h>

#include "../inc/Constants.h"

int loadTextures(const char *path, ALLEGRO_BITMAP *textures[]) {
    char filepath[30];
    
    for (int i = 0; i < NUM_TEXTURES; i++) {
        // Build file path
        snprintf(filepath, sizeof(filepath), "%s%d.png", path, i + 1);
        // Load texture
        textures[i] = al_load_bitmap(filepath);
        // Check for error
        if (!textures[i]) {
            return 0;
        }
    }
    
    return 1;
}
