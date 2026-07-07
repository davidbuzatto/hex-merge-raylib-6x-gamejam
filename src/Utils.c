#include <stdlib.h>
#include <math.h>

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "Utils.h"

float apothem( float radius ) {
    return radius * sqrtf( 3.0f ) / 2.0f;
}
