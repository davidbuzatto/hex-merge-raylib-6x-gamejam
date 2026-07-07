/**
 * @file GameWorld.c
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "GameWorld.h"
#include "Macros.h"
#include "ResourceManager.h"
#include "Utils.h"

static void createHexGrid( GameWorld *gw, int q, float radius );
static void connextHexGrid( Hex *hexGrid, int hexCount );
static void connectHexToNeighbors( Hex *hexGrid, int hexCount );

static int gridQuantities[] = { 3, 5, 7, 9, 11, 13 };
static int gridRadii[] = { 100, 60, 44, 36, 30, 26 };
int gridId = 5;

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld *createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    /*for ( int i = 0; i < 6; i++ ) {
        trace( 
            "%d %.2f %.2f %.2f", 
            gridQuantities[i], 
            gridRadii[i], 
            apothem( gridRadii[i] ), 
            apothem( gridRadii[i] ) * 2 * gridQuantities[i]
        );
    }*/

    createHexGrid( gw, gridQuantities[gridId], gridRadii[gridId] );
    connextHexGrid( gw->hexGrid, gw->hexCount );

    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void updateGameWorld( GameWorld *gw, float delta ) {

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( BLACK );

    int xc = GetScreenWidth() / 2;
    int yc = GetScreenHeight() / 2;

    drawHexGrid( gw->hexGrid, gw->hexCount, false );

    EndDrawing();

}

static void createHexGrid( GameWorld *gw, int centerLineQuantity, float radius ) {

    gw->hexCount = 0;
    
    float hApothem = apothem( radius );
    float vApothem = apothem( 2 * hApothem );
    float startX = GetScreenWidth() / 2 - ( hApothem * 2 * centerLineQuantity ) / 2 + hApothem;
    float startY = GetScreenHeight() / 2 - ( vApothem * centerLineQuantity ) / 2 + vApothem / 2;
    
    bool decrease = false;
    int linesAboveAndBelow = centerLineQuantity / 2;
    int lineQuantity = centerLineQuantity - linesAboveAndBelow;

    for ( int i = 0; i < centerLineQuantity; i++ ) {
        if ( i == linesAboveAndBelow ) {
            decrease = true;
        }
        int offset = ( centerLineQuantity - lineQuantity ) * hApothem;
        for ( int j = 0; j < lineQuantity; j++ ) {
            Vector2 center = { startX + hApothem * 2 * j + offset, startY + vApothem * i };
            initHex( &gw->hexGrid[gw->hexCount++], center, radius );
        }
        if ( decrease ) {
            lineQuantity--;
        } else {
            lineQuantity++;
        }
    }

}

static void connextHexGrid( Hex *hexGrid, int hexCount ) {
    for ( int i = 0; i < hexCount; i++ ) {
        connectHexToNeighbors( &hexGrid[i], hexCount );
    }
}

static void connectHexToNeighbors( Hex *source, int hexCount ) {

    // probe scan
    int angle = 0;
    int angleInc = 60;
    int targetFoundCount = 0;

    for ( int p = 0; p < 6; p++ ) {
        Vector2 probe = {
            source->center.x + ( source->radius * 2 ) * cosf( DEG2RAD * angle ),
            source->center.y + ( source->radius * 2 ) * sinf( DEG2RAD * angle )
        };
        for ( int t = 0; t < hexCount; t++ ) {
            Hex *target = &source[t];
            if ( source != target ) {
                if ( CheckCollisionPointCircle( probe, target->center, 20 ) ) {
                    source->neighbors[targetFoundCount++] = target;
                    break;
                }
            }
        }
        angle += angleInc;
        if ( targetFoundCount == 6 ) {
            return;
        }
    }

}
