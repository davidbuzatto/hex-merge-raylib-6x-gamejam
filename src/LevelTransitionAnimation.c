#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "Hex.h"
#include "LevelTransitionAnimation.h"
#include "Macros.h"
#include "Utils.h"

static void update( LevelTransitionAnimation *lta, float delta );
static void draw( LevelTransitionAnimation *lta );
static void drawSimpleHex( Hex *h, unsigned int strokeColor );
static void drawSimpleHexGrid( Hex *hexGrid, int hexCount, unsigned int strokeColor );
static void prepareSimpleHexGrid( Hex *hexGrid, int centerLineQuantity, float hexRadius, int *hexCount );

static const float animationUnitTime = 0.2f;

void initLevelTransitionAnimation( LevelTransitionAnimation *lta ) {
    lta->running = false;
    lta->update = update;
    lta->draw = draw;
}

void prepareLevelTransitionAnimation( LevelTransitionAnimation *lta, int chgCenterLineQuantity, float chgHexRadius, int nhgCenterLineQuantity, float nhgHexRadius ) {
    lta->chgCenterLineQuantity = chgCenterLineQuantity;
    lta->chgCount = 0;
    lta->chgHexRadius = chgHexRadius;
    lta->nhgCenterLineQuantity = nhgCenterLineQuantity;
    lta->nhgCount = 0;
    lta->nhgHexRadius = nhgHexRadius;
    lta->animationUnitCounter = animationUnitTime;
    prepareSimpleHexGrid( lta->currentHexGrid, lta->chgCenterLineQuantity, lta->chgHexRadius, &lta->chgCount );
    prepareSimpleHexGrid( lta->nextHexGrid, lta->nhgCenterLineQuantity, lta->nhgHexRadius, &lta->nhgCount );
}

static void update( LevelTransitionAnimation *lta, float delta ) {

    if ( !lta->running ) {
        return;
    }

}

static void draw( LevelTransitionAnimation *lta ) {
    if ( lta->running ) {
        drawSimpleHexGrid( lta->currentHexGrid, lta->chgCount, ColorToInt( DARKGRAY ) );
        drawSimpleHexGrid( lta->nextHexGrid, lta->nhgCount, ColorToInt( DARKGRAY ) );
    }
}

static void drawSimpleHex( Hex *h, unsigned int strokeColor ) {
    DrawPoly( h->center, 6, h->radius, 90.0f, GetColor( h->color ) );
    if ( h->color != HEX_BLANK_COLOR ) {
        strokeColor = h->color;
    }
    DrawPolyLines( h->center, 6, h->radius, 90.0f, GetColor( strokeColor ) );
}

static void drawSimpleHexGrid( Hex *hexGrid, int hexCount, unsigned int strokeColor ) {
    for ( int i = 0; i < hexCount; i++ ) {
        Hex *h = &hexGrid[i];
        drawSimpleHex( h, strokeColor );
    }
}

static void prepareSimpleHexGrid( Hex *hexGrid, int centerLineQuantity, float hexRadius, int *hexCount ) {

    int hc = 0;
    
    float hApothem = apothem( hexRadius );
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
            if ( hc < MAX_HEX_GRID_COUNT ) {
                initHex( &hexGrid[hc++], center, hexRadius );
            }
        }
        if ( decrease ) {
            lineQuantity--;
        } else {
            lineQuantity++;
        }
    }

    *hexCount = hc;

}