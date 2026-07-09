#pragma once

#include <stdbool.h>

#include "raylib/raylib.h"

#include "Hex.h"
#include "Macros.h"

typedef struct LevelTransitionAnimation LevelTransitionAnimation;

typedef enum LevelTransitionAnimationState {
    LTA_STATE_EXPLODING_CURRENT_GRID,
    LTA_STATE_SHOWING_NEXT_GRID,
    LTA_STATE_FINISHED
} LevelTransitionAnimationState;

typedef struct SimpleHex {
    Vector2 currentCenter;
    Vector2 startCenter;
    Vector2 targetCenter;
    float currentRadius;
    float startRadius;
    float targetRadius;
    float apothem;
    unsigned int color;
} SimpleHex;

struct LevelTransitionAnimation {

    SimpleHex currentHexGrid[MAX_HEX_GRID_COUNT];
    int chgCenterLineQuantity;
    float chgHexRadius;
    int chgCount;

    SimpleHex nextHexGrid[MAX_HEX_GRID_COUNT];
    int nhgCenterLineQuantity;
    float nhgHexRadius;
    int nhgCount;
    
    bool running;
    LevelTransitionAnimationState state;

    void (*update)( LevelTransitionAnimation *lta, float delta );
    void (*draw)( LevelTransitionAnimation *lta );

};

void initLevelTransitionAnimation( LevelTransitionAnimation *lta );
void prepareLevelTransitionAnimation( LevelTransitionAnimation *lta, int chgCenterLineQuantity, float chgHexRadius, int nhgCenterLineQuantity, float nhgHexRadius );
