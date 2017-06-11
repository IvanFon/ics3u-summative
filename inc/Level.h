/// @file Level.h
/// @brief Level loading
/// @author Ivan Fonseca

#ifndef _INC_LEVELS_H
#define _INC_LEVELS_H

#include <allegro5/allegro.h>

#include "Physics.h"
#include "Constants.h"

/// @brief Stores a tile
struct Tile {
    /// @brief Texture
    int texture;
    /// @brief Rectangle
    Rectangle rect;
};

/// @brief Stores a game level
struct Level {
    /// @brief Where the player will spawn
    Vector spawn;
    /// @brief Array of tiles (number represents texture)
    Tile tiles[LVL_HEIGHT][LVL_WIDTH];
};

/// @brief Loads a level from a file
/// @param filename The file containing the level to load
/// @param level The Level to load into from the file
/// @return 0 on error, 1 otherwise
int loadLevel(const char *filename, Level &level);

/// @brief Loads all levels
/// @param path Folder to load levels from (must end with a "/")
/// @param levels Array to load levels into
/// @return 0 on error, 1 otherwise
int loadLevels(char *path, Level *levels);

/// @brief Draws a level
/// @param textures Array of textures to use
/// @param level The Level to draw
void drawLevel(ALLEGRO_BITMAP *textures[], Level level);

#endif
