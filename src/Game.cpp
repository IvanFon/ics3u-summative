/// @file Game.cpp
/// @brief Main game loop
/// @author Ivan Fonseca

#include "../inc/Game.h"

#include <allegro5/allegro.h>

#include "../inc/Assets.h"
#include "../inc/Init.h"
#include "../inc/Input.h"
#include "../inc/Quit.h"
#include "../inc/Physics.h"
#include "../inc/Player.h"
#include "../inc/Level.h"
#include "../inc/States.h"
#include "../inc/LevelSelect.h"

int curLvl = 0;
bool levelLoaded = false;

void gameLoop() {
    al_start_timer(timer);
    bool redraw = true;
    bool inputChanged = false;
    while (true) {
        // Finish loading level
        if (!levelLoaded) {
            levelLoaded = true;
            player.rect.pos = (campaign) ? levels[curLvl].spawn : usrLvl.spawn;
        }
        
        // Get events
        ALLEGRO_EVENT event;
        al_wait_for_event(evQueue, &event);
        
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                quitGame();
                break;

            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                updateInput(event, KEY_DOWN);
                inputChanged = true;
                break;

            case ALLEGRO_EVENT_KEY_UP:
                updateInput(event, KEY_UP);
                inputChanged = true;
                break;
        }
        
        // Input changed
        if (inputChanged) {
            if (input.escape) {
                quitGame();
            }
        }
        
        runState();
        
        inputChanged = false;
        
        if (redraw && al_is_event_queue_empty(evQueue)) {
            redraw = false;
            al_clear_to_color(COL_BLACK);
            drawLevel(textures, (campaign) ? levels[curLvl] : usrLvl);
            al_draw_bitmap(player.texture, player.rect.pos.x, player.rect.pos.y, 0);
            al_flip_display();
        }
    }
}
