#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "Macros.h"
#include "Utils.h"

float apothem( float radius ) {
    return radius * sqrtf( 3.0f ) / 2.0f;
}

unsigned int colorBlend( unsigned int color1, unsigned int color2 ) {

    switch ( color1 ) {
        case HEX_RED:
            switch ( color2 ) {
                case HEX_YELLOW: return HEX_ORANGE;
                case HEX_BLUE: return HEX_PURPLE;
                default: return HEX_BLANK_COLOR;
            }
            break;
        case HEX_YELLOW:
            switch ( color2 ) {
                case HEX_RED: return HEX_ORANGE;
                case HEX_BLUE: return HEX_GREEN;
                default: return HEX_BLANK_COLOR;
            }
            break;
        case HEX_BLUE:
            switch ( color2 ) {
                case HEX_YELLOW: return HEX_GREEN;
                case HEX_RED: return HEX_PURPLE;
                default: return HEX_BLANK_COLOR;
            }
            break;
        case HEX_ORANGE:
            switch ( color2 ) {
                case HEX_RED: return HEX_RED_ORANGE;
                case HEX_YELLOW: return HEX_YELLOW_ORANGE;
                default: return HEX_BLANK_COLOR;
            }
            break;
        case HEX_GREEN:
            switch ( color2 ) {
                case HEX_YELLOW: return HEX_YELLOW_GREEN;
                case HEX_BLUE: return HEX_BLUE_GREEN;
                default: return HEX_BLANK_COLOR;
            }
            break;
        case HEX_PURPLE:
            switch ( color2 ) {
                case HEX_BLUE: return HEX_BLUE_PURPLE;
                case HEX_RED: return HEX_RED_PURPLE;
                default: return HEX_BLANK_COLOR;
            }
            break;
        default: return HEX_BLANK_COLOR;
    }

    // unreachable
    return HEX_BLANK_COLOR;

}

int clampInt( int value, int min, int max ) {
    if ( value < min ) return min;
    if ( value > max ) return max;
    return value;
}