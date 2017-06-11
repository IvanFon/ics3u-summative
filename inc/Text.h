/// @file Text.h
/// @brief Handles loading of fonts and drawing text
/// @author Ivan Fonseca

#ifndef _INC_TEXT_H
#define _INC_TEXT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

/// @brief Contains all the fonts used in the game
struct Fonts {
    /// @brief Roboto regular
    ALLEGRO_FONT *robotoReg;
};

/// @brief All the fonts
extern Fonts fonts;

/// @brief Loads fonts
/// @return 0 on error, 1 otherwise
int loadFonts();

#endif