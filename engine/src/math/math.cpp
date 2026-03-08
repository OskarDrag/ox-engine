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




vec2 v2zero() {
    return vec2 {
        0.0f, 0.0f
    };
}

vec2 v2one() {
    return vec2 {
        1.0f, 1.0f
    };
}

vec2 v2up() {
    return vec2 {
        0.0f, 1.0f
    };
}

vec2 v2down() {
    return vec2 {
        0.0f, -1.0f
    };
}

vec2 v2right() {
    return vec2 {
        1.0f, 0.0f
    };
}

vec2 v2left() {
    return vec2 {
        -1.0f, 0.0f
    };
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

float v2dotProduct(vec2 value1, vec2 value2) {
    return
    ( value1.x * value2.x ) + ( value1.y * value2.y );
}




vec3 v3zero() {
    return vec3 {
        0.0f, 0.0f, 0.0f
    };
}

vec3 v3one() {
    return vec3 {
        1.0f, 1.0f, 1.0f
    };
}

vec3 v3up() {
    return vec3 {
        0.0f, 1.0f, 0.0f
    };
}

vec3 v3down() {
    return vec3 {
        0.0f, -1.0f, 0.0f
    };
}

vec3 v3right() {
    return vec3 {
        1.0f, 0.0f, 0.0f
    };
}

vec3 v3left() {
    return vec3 {
        -1.0f, 0.0f, 0.0f
    };
}

vec3 v3forward() {
    return vec3 {
        0.0f, 0.0f, 1.0f
    };
}

vec3 v3backward() {
    return vec3 {
        0.0f, 0.0f, -1.0f
    };
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

float v3len(vec3 value) {
    vec2 vector1 = { value.x, value.y};
    vec2 vector2 = { v2len(vector1), value.z };
    return v2len(vector2);
}

float v3lenSqrd(vec3 value) {
    vec2 vector1 = { value.x, value.y};
    vec2 vector2 = { v2len(vector1), value.z };
    return v2lenSqrd(vector2);
}

void v3norm(vec3* value) {
    float length = v3len(*value);
    value->x /= length;
    value->y /= length;
    value->z /= length;
}

vec3 v3normalised(vec3 value) {
    v3norm(&value);
    return value;
}

float v3dotProduct(vec3 value1, vec3 value2) {
    return
    ( value1.x * value2.x ) + ( value1.y * value2.y ) + ( value1.z * value2.z );
}

vec3 v3crossProduct(vec3 value1, vec3 value2) {
    return vec3 {
        ((value1.y * value2.z) - (value1.z * value2.y)),
        ((value1.z * value2.x) - (value1.x * value2.z)),
        ((value1.x * value2.y) - (value1.y * value2.x))
    };
}





vec4 v4zero() {
    return vec4 {
        0.0f, 0.0f, 0.0f, 0.0f
    };
}

vec4 v4one() {
    return vec4 {
        1.0f, 1.0f, 1.0f, 1.0f
    };
}

vec4 v4add (vec4 value1, vec4 value2) {
    return vec4 {
            value1.x + value2.x,
            value1.y + value2.y,
            value1.z + value2.z,
            value1.w + value2.w };
}

vec4 v4sub (vec4 value1, vec4 value2) {
    return vec4 {
            value1.x - value2.x,
            value1.y - value2.y,
            value1.z - value2.z,
            value1.w - value2.w };
}

vec4 v4mul (vec4 value1, vec4 value2) {
    return vec4 {
            value1.x * value2.x,
            value1.y * value2.y,
            value1.z * value2.z,
            value1.w * value2.w };
}

vec4 v4div (vec4 value1, vec4 value2) {
    return vec4 {
            value1.x / value2.x,
            value1.y / value2.y,
            value1.z / value2.z,
            value1.w / value2.w };
}

vec4 v4mulScalar(vec4 value1, float multiplier) {
    return vec4 {
            value1.x * multiplier,
            value1.y * multiplier,
            value1.z * multiplier,
            value1.w * multiplier };
}

vec4 v4divScalar(vec4 value1, float multiplier) {
    return vec4 {
            value1.x / multiplier,
            value1.y / multiplier,
            value1.z / multiplier,
            value1.w / multiplier };
}

float v4dotProduct(vec4 value1, vec4 value2) {
    return
    ( value1.x * value2.x ) + ( value1.y * value2.y ) + ( value1.z * value2.z ) + ( value1.w * value2.w );
}

vec3 v4tov3 (vec4 value1) {
    return vec3 {
        value1.x, value1.y, value1.z
    };
}

vec4 v3tov4 (vec3 value1, float w) {
    return vec4 {
        value1.x, value1.y, value1.z, w
    };
}
