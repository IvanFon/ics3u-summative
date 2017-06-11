/// @file Sprite.cpp
/// @brief Sprite functions
/// @author Ivan Fonseca

#include "../inc/Sprite.h"

#include <allegro5/allegro.h>

void drawSprite(Sprite sprite) {
    al_draw_bitmap(
        sprite.texture,
        sprite.rect.pos.x,
        sprite.rect.pos.y,
        0
    );
}