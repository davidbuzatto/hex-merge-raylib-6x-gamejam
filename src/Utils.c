#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "Macros.h"
#include "Utils.h"

/*
// primary
#define HEX_RED           0xd62028ff
#define HEX_YELLOW        0xfced23ff
#define HEX_BLUE          0x3f61abff

// secondary
#define HEX_ORANGE        0xf6841dff // red + yellow
#define HEX_GREEN         0x05b250ff // yellow + blue
#define HEX_PURPLE        0x723b96ff // blue + red

// tertiary
#define HEX_RED_ORANGE    0xf26623ff // red + orange
#define HEX_YELLOW_ORANGE 0xfcb413ff // yellow + orange
#define HEX_YELLOW_GREEN  0x8dc541ff // yellow + green
#define HEX_BLUE_GREEN    0x2ebcb2ff // blue + green
#define HEX_BLUE_PURPLE   0x4c499bff // blue + purple
#define HEX_RED_PURPLE    0xb03b94ff // red + purple
*/

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