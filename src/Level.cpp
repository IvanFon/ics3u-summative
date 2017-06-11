/// @file Level.cpp
/// @brief Level loading
/// @author Ivan Fonseca

#include "../inc/Level.h"

#include <stdio.h>

#include <allegro5/allegro.h>

#include "../inc/Assets.h"
#include "../inc/Physics.h"
#include "../inc/Constants.h"

int loadLevel(const char *filename, Level &level) {
    // Attempt to open file
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error loading level \"%s\".\n", filename);
        return 0;
    }
    
    // Read in spawn point
    int spawnX, spawnY;
    fscanf(file, "%d %d", &spawnX, &spawnY);
    level.spawn = { spawnX * (float)TILE_WIDTH, spawnY * (float)TILE_WIDTH };

    // Read in tiles
    for (int y = 0; y < LVL_HEIGHT; y++) {
        for (int x = 0; x < LVL_WIDTH; x++) {
            Tile tile;
            fscanf(file, "%d", &tile.texture);
            Vector pos = { x * (float)TILE_WIDTH, y * (float)TILE_WIDTH };
            Vector size = { TILE_WIDTH, TILE_WIDTH };
            Rectangle tileRect = { pos, size };
            tile.rect = tileRect;
            level.tiles[y][x] = tile;
        }
    }

    fclose(file);
    
    return 1;
}

int loadLevels(char *path, Level *levels) {
    for (int i = 0; i < NUM_LEVELS; i++) {
        // Build file path
        char filepath[30];
        snprintf(filepath, sizeof(filepath), "%s%d.txt", path, i + 1);
        // Load level
        Level level;
        if (!loadLevel(filepath, level)) {
            // loadLevel already prints an error, we don't need a message here
            return 0;
        }
        levels[i] = level;
    }

    return 1;
}

void drawLevel(ALLEGRO_BITMAP *textures[], Level level) {
    for (int y = 0; y < LVL_HEIGHT; y++) {
        for (int x = 0; x < LVL_WIDTH; x++) {
            al_draw_bitmap(textures[level.tiles[y][x].texture], x * TILE_WIDTH, y * TILE_WIDTH, 0);
        }
    }
}
