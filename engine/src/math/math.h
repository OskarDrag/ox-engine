#pragma once

#include "types.h"
#include "../defines.h"

#define PI 3.14159265358979323846
#define PI_TWO (PI * 2)
#define PI_HALF (PI / 2)
#define PI_QUARTER (PI / 4)
#define PI_INVERTED (1 / PI)
#define PI_TWO_INVERTED (1 / PI_TWO)
#define SQRT2 1.41421356237309504880
#define SQRT3 1.73205080756887729352
#define SQRT2_INVERTED (1 / SQRT2)
#define SQRT3_INVERTED (1 / SQRT3)
#define DEG_TO_RAD (PI / 180.0f)
#define RAD_TO_DEG (180.0f / PI)
#define EPSILON 1.192092896e-07f



OX_API float ox_sqrt(float x);

OX_API float ox_sin(float x);

OX_API float ox_cos(float x);

OX_API float ox_tan(float x);

OX_API float ox_ctan(float x);

OX_API float ox_abs(float x);

OX_API bool ox_compare(float value1, float value2);




OX_API vec2 v2zero();

OX_API vec2 v2one();

OX_API vec2 v2up();

OX_API vec2 v2down();

OX_API vec2 v2right();

OX_API vec2 v2left();

OX_API vec2 v2add (vec2 value1, vec2 value2);

OX_API vec2 v2sub (vec2 value1, vec2 value2);

OX_API vec2 v2mul (vec2 value1, vec2 value2);

OX_API vec2 v2div (vec2 value1, vec2 value2);

OX_API vec2 v2mulScalar(vec2 value1, float multiplier);

OX_API vec2 v2divScalar(vec2 value1, float multiplier);

OX_API float v2len(vec2 value);

OX_API float v2lenSqrd(vec2 value);

OX_API void v2norm(vec2* value);

OX_API vec2 v2normalised(vec2 value);

OX_API float v2dotProduct(vec2 value1, vec2 value2);




OX_API vec3 v3zero();

OX_API vec3 v3one();

OX_API vec3 v3up();

OX_API vec3 v3down();

OX_API vec3 v3right();

OX_API vec3 v3left();

OX_API vec3 v3forward();

OX_API vec3 v3backward();

OX_API vec3 v3add (vec3 value1, vec3 value2);

OX_API vec3 v3sub (vec3 value1, vec3 value2);

OX_API vec3 v3mul (vec3 value1, vec3 value2);

OX_API vec3 v3div (vec3 value1, vec3 value2);

OX_API vec3 v3mulScalar(vec3 value1, float multiplier);

OX_API vec3 v3divScalar(vec3 value1, float multiplier);

OX_API float v3len(vec3 value);

OX_API float v3lenSqrd(vec3 value);

OX_API void v3norm(vec3* value);

OX_API vec3 v3normalised(vec3 value);

OX_API float v3dotProduct(vec3 value1, vec3 value2);

OX_API vec3 v3crossProduct(vec3 value1, vec3 value2);




OX_API vec4 v4zero();

OX_API vec4 v4one();

OX_API vec4 v4add (vec4 value1, vec4 value2);

OX_API vec4 v4sub (vec4 value1, vec4 value2);

OX_API vec4 v4mul (vec4 value1, vec4 value2);

OX_API vec4 v4div (vec4 value1, vec4 value2);

OX_API vec4 v4mulScalar(vec4 value1, float multiplier);

OX_API vec4 v4divScalar(vec4 value1, float multiplier);

OX_API float v4dotProduct(vec4 value1, vec4 value2);

OX_API vec3 v4tov3 (vec4 value1);

OX_API vec4 v3tov4 (vec3 value1, float w);