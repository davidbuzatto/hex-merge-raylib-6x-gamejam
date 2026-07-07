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
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "GameWorld.h"
#include "ResourceManager.h"

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld *createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    

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

float apotema( float radius ) {
    return radius * sqrtf( 3.0f ) / 2.0f;
}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( BLACK );

    int xc = GetScreenWidth() / 2;
    int yc = GetScreenHeight() / 2;

    int q = 31;
    float hr = 10;
    float apH = apotema( hr );
    float apV = apotema( 2 * apH );
    float startX = GetScreenWidth() / 2 - ( apH * 2 * q ) / 2;
    float startY = GetScreenHeight() / 2 - ( apV * q ) / 2 + apV / 2;
    
    int cSkipStart = 0;
    int skipStart = q / 4;

    if ( ( q - 3 ) % 4 == 0 ) {
        cSkipStart++;
        skipStart++;
    }

    int cSkipEnd = 1;
    int skipEnd = skipStart;

    int mid = q / 2;

    for ( int i = 0; i < q; i++ ) {

        int d = q - 5;
        float offset;

        if ( i < mid ) {
            if ( cSkipStart == 2 ) {
                cSkipStart = 0;
                skipStart--;
            }
            if ( cSkipStart == 1 ) {
                skipEnd--;
            }
            cSkipStart++;
        } else if ( i == mid ) {
            skipStart = 0;
            skipEnd = 0;
            cSkipStart = 0;
        } else {
            if ( i == mid + 1 ) {
                skipStart = 1;
            }
            if ( cSkipStart == 1 ) {
                skipEnd++;
            }
            if ( cSkipStart == 2 ) {
                cSkipStart = 0;
                skipStart++;
            }
            cSkipStart++;
        }

        if ( d % 4 == 0 ) {
            offset = i % 2 == 0 ? apH : 0;
        } else {
            offset = i % 2 == 0 ? 0 : apH;
        }

        for ( int j = skipStart; j < q - skipEnd; j++ ) {

            Color c = BLACK;

            if ( i == q / 2 ) {
                c = GREEN;
            } else if ( i < q / 2 ) {
                c = RED;
            } else {
                c = BLUE;
            }

            DrawPoly( 
                (Vector2) { 
                    startX + ( 2 * apH ) * j + offset,
                    startY + apV * i
                },
                6,
                hr,
                90.0f,
                c
            );

            DrawPolyLines( 
                (Vector2) { 
                    startX + ( 2 * apH ) * j + offset,
                    startY + apV * i
                },
                6,
                hr,
                90.0f,
                WHITE
            );

        }
    }

    DrawCircle( xc, yc, 5, BLUE );
    

    EndDrawing();

}