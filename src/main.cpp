/// @file main.cpp
/// @brief Entry point
/// @author Ivan Fonseca

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../inc/Init.h"
#include "../inc/Assets.h"
#include "../inc/Menu.h"
#include "../inc/Quit.h"
#include "../inc/Settings.h"

int main() {

    // Initialize Allegro
    if (!init()) {
        fprintf(stderr, "Error during initialization!\n");
        return 1;
    }

    // Load assets
    if (!loadAssets()) {
        fprintf(stderr, "Error loading assets!\n");
        return 1;
    }

    // Show the menu
    showMenu();

    // Cleanup
    quitGame();
    
    return 0;
}
