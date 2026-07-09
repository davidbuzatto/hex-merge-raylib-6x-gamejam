#pragma once

#include <stdbool.h>

#include "raylib/raylib.h"

#include "Hex.h"
#include "Macros.h"

typedef struct LevelTransitionAnimation LevelTransitionAnimation;

struct LevelTransitionAnimation {

    Hex currentHexGrid[MAX_HEX_GRID_COUNT];
    int chgCenterLineQuantity;
    float chgHexRadius;
    int chgCount;

    Hex nextHexGrid[MAX_HEX_GRID_COUNT];
    int nhgCenterLineQuantity;
    float nhgHexRadius;
    int nhgCount;

    float animationUnitCounter;
    bool running;

    void (*update)( LevelTransitionAnimation *lta, float delta );
    void (*draw)( LevelTransitionAnimation *lta );

};

void initLevelTransitionAnimation( LevelTransitionAnimation *lta );
void prepareLevelTransitionAnimation( LevelTransitionAnimation *lta, int chgCenterLineQuantity, float chgHexRadius, int nhgCenterLineQuantity, float nhgHexRadius );
