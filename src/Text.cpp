/// @file Text.cpp
/// @brief Handles loading of fonts and drawing text
/// @author Ivan Fonseca

#include "../inc/Text.h"

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "../inc/Constants.h"

Fonts fonts;

int loadFonts() {
    fonts.robotoReg = al_load_ttf_font(FONT_PATHS[ROBOTOREG], 20, 0);
    if (!fonts.robotoReg) {
        fprintf(stderr, "Error loading Roboto regular!\n");
        return 0;
    }

    return 1;
}