#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"

#include "Hex.h"

void initHex( Hex *h, Vector2 center, float radius ) {

    h->center = center;
    h->radius = radius;
    h->color = 0x000000ff;

    for ( int i = 0; i < 6; i++ ) {
        h->neighbors[i] = NULL;
    }

}

void drawHex( Hex *h ) {
    DrawPoly( h->center, 6, h->radius, 90.0f, GetColor( h->color ) );
    DrawPolyLines( h->center, 6, h->radius, 90.0f, WHITE );
}

void drawHexGrid( Hex *hexGrid, int hexCount, bool showConnections ) {
    for ( int i = 0; i < hexCount; i++ ) {
        Hex *h = &hexGrid[i];
        drawHex( h );
    }
    if ( showConnections ) {
        drawHexGridConnections( hexGrid, hexCount );
    }
}

void drawHexGridConnections( Hex *hexGrid, int hexCount ) {
    for ( int i = 0; i < hexCount; i++ ) {
        Hex *h = &hexGrid[i];
        for ( int j = 0; j < 6; j++ ) {
            Hex *t = h->neighbors[j];
            if ( t != NULL ) {
                DrawLineV( h->center, t->center, WHITE );
            }
        }
    }
}
