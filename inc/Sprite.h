/// @file Sprite.h
/// @brief Sprite functions
/// @author Ivan Fonseca

#ifndef _INC_SPRITE_H
#define _INC_SPRITE_H

#include <allegro5/allegro.h>

#include "Physics.h"

/// @brief A generic sprite
struct Sprite {
    /// @brief The Sprite's texture
    ALLEGRO_BITMAP *texture;
    /// @brief The Sprite's position and size
    Rectangle rect;
};

/// @brief Draws a sprite
/// @param sprite The sprite to draw
void drawSprite(Sprite sprite);

#endif
