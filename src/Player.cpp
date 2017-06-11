/// @file Player.cpp
/// @brief Player-specific functions
/// @author Ivan Fonseca

#include "../inc/Player.h"

#include "../inc/Constants.h"
#include "../inc/Physics.h"
#include "../inc/Level.h"
#include "../inc/Assets.h"
#include "../inc/Game.h"
#include "../inc/Utils.h"
#include "../inc/States.h"
#include "../inc/Input.h"

Vector playerVel = { 0, 0 };

void handleCollisions(bool xAxis = true) {
    for (int y = 0; y < LVL_HEIGHT; y++) {
        for (int x = 0; x < LVL_WIDTH; x++) {
            // Store current tile
            Tile curTile = levels[curLvl].tiles[y][x];

            // Check if this is a solid tile
            if (contains(SOLID_TILES, NUM_SOLID_TILES, curTile.texture)) {
                if (collides(player.rect, curTile.rect)) {
                    // Check if its the change level tile
                	if (curTile.texture == 2) {
                        // Change level
                        curLvl++;
                        levelLoaded = false;
					} else if (xAxis) {
                        player.rect.pos.x += collisionDepthX(player.rect, curTile.rect);
                        playerVel.x = 0;
                    } else {
                        float depth = collisionDepthY(player.rect, curTile.rect);
                        player.rect.pos.y += depth;
                        if (depth < 0) {
                            playerState = { playerStateWalking };
                        }
                        playerVel.y = 0;
                    }
                }
            }
        }
    }
}

void horizontalMove(bool jumping = false) {
    // Handle input
    if (input.left) {
        if (playerVel.x > 0) {
            playerVel.x -= PLAYER_DECCEL_BOOST * ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X);
        } else {
            playerVel.x -= ((jumping) ? PLAYER_ACCEL_AIR_X : PLAYER_ACCEL_X);
        }
    } else if (input.right) {
        if (playerVel.x < 0) {
            playerVel.x += PLAYER_DECCEL_BOOST * ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X);
        } else {
            playerVel.x += ((jumping) ? PLAYER_ACCEL_AIR_X : PLAYER_ACCEL_X);
        }
    } else {
        if (playerVel.x < 0) {
            if (playerVel.x + ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X) > 0) {
                playerVel.x = 0;
            } else {
                playerVel.x += ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X);
            }
        } else if (playerVel.x > 0) {
            if (playerVel.x - ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X) < 0) {
                playerVel.x = 0;
            } else {
                playerVel.x -= ((jumping) ? PLAYER_DECCEL_AIR_X : PLAYER_DECCEL_X);
            }
        }

        // Clamp horizontal speed
        playerVel.x = clamp(playerVel.x, PLAYER_MAX_VEL_X * -1, PLAYER_MAX_VEL_X);
    }
}

void verticalMove() {
    // Gravity
    playerVel.y += GRAVITY_ACCEL;

    // Move and collide
    player.rect.pos.y += playerVel.y;
    handleCollisions(false);

    // Check if player fell out of world
    if (player.rect.pos.y + player.rect.size.y >= SCREEN.y) {
        // Restart level
        levelLoaded = false;
    }
}

void move(bool jumping) {
    horizontalMove(jumping);
    // Hit edges
    if (player.rect.pos.x + playerVel.x >= 0 && player.rect.pos.x + player.rect.size.x + playerVel.x <= SCREEN.x) {
        player.rect.pos.x += playerVel.x;
    }
    handleCollisions(true);

    verticalMove();
    // Hit edges
    if (player.rect.pos.y + player.rect.size.y + playerVel.y >= 0 && player.rect.pos.y + playerVel.y <= SCREEN.y) {
        player.rect.pos.y += playerVel.y;
    }
    handleCollisions(false);
}
