#include "math.h"

#include <cmath>


float ox_sqrt(float x) {
    return sqrt(x);
}

float ox_sin(float x) {
    return std::sin(DEG_TO_RAD * x);
}

float ox_cos(float x) {
    return std::cos(DEG_TO_RAD * x);
}

float ox_tan(float x) {
    return std::tan(DEG_TO_RAD * x);
}

float ox_ctan(float x) {
    return 1.0f / (std::tan(DEG_TO_RAD * x));
}

float ox_abs(float x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

bool ox_compare(float value1, float value2) {
    if (abs(value1 - value2) > EPSILON) {
        return 0;
    }
    return 1;
}




vec2 v2add (vec2 value1, vec2 value2) {
    return vec2 {
            value1.x + value2.x,
            value1.y + value2.y };
}

vec2 v2sub (vec2 value1, vec2 value2) {
    return vec2 {
            value1.x - value2.x,
            value1.y - value2.y };
}

vec2 v2mul (vec2 value1, vec2 value2) {
    return vec2 {
            value1.x * value2.x,
            value1.y * value2.y };
}

vec2 v2div (vec2 value1, vec2 value2) {
    return vec2 {
            value1.x / value2.x,
            value1.y / value2.y };
}

vec2 v2mulScalar(vec2 value1, float multiplier) {
    return vec2 {
            value1.x * multiplier,
            value1.y * multiplier };
}

vec2 v2divScalar(vec2 value1, float multiplier) {
    return vec2 {
            value1.x / multiplier,
            value1.y / multiplier };
}

float v2len (vec2 value) {
    return ox_sqrt(( value.x * value.x ) + ( value.y * value.y ));
}

float v2lenSqrd(vec2 value) {
    return ( value.x * value.x ) + ( value.y * value.y );
}

void v2norm(vec2* value) {
    float length = v2len(*value);
    value->x /= length;
    value->y /= length;
}

vec2 v2normalised(vec2 value) {
    v2norm(&value);
    return value;
}




vec3 v3add (vec3 value1, vec3 value2) {
    return vec3 {
            value1.x + value2.x,
            value1.y + value2.y,
            value1.z + value2.z };
}

vec3 v3sub (vec3 value1, vec3 value2) {
    return vec3 {
            value1.x - value2.x,
            value1.y - value2.y,
            value1.z - value2.z };
}

vec3 v3mul (vec3 value1, vec3 value2) {
    return vec3 {
            value1.x * value2.x,
            value1.y * value2.y,
            value1.z * value2.z };
}

vec3 v3div (vec3 value1, vec3 value2) {
    return vec3 {
            value1.x / value2.x,
            value1.y / value2.y,
            value1.z / value2.z };
}

vec3 v3mulScalar(vec3 value1, float multiplier) {
    return vec3 {
            value1.x * multiplier,
            value1.y * multiplier,
            value1.z * multiplier };
}

vec3 v3divScalar(vec3 value1, float multiplier) {
    return vec3 {
            value1.x / multiplier,
            value1.y / multiplier,
            value1.z / multiplier };
}
