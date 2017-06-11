/// @file Init.h
/// @brief Initializes Allegro
/// @author Ivan Fonseca

#ifndef _INC_INIT_H
#define _INC_INIT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *evQueue;
extern ALLEGRO_TIMER *timer;

// Loading screens
extern ALLEGRO_BITMAP *loadingAllegro;
extern ALLEGRO_BITMAP *loadingAssets;

/// @brief Initializes Allegro and Allegro addons
/// @return 0 on error, 1 otherwise
int init();

#endif