#pragma once

#include <stdbool.h>

#include "raylib/raylib.h"

typedef struct Hex Hex;

struct Hex {
    Vector2 center;
    float radius;
    unsigned int color;
    Hex *neighbors[6];
};

void initHex( Hex *h, Vector2 center, float radius );
void drawHex( Hex *h );
void drawHexGrid( Hex *hexGrid, int hexCount, bool showConnections );
void drawHexGridConnections( Hex *hexGrid, int hexCount );
bool checkCollisionPointHex( Vector2 point, Hex *h );