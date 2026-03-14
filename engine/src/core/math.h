#pragma once

#include "../defines.h"

struct vec2 {
    union {
        float data[2];
        struct{
            union {
                float x, r, u;
            };
            union {
                float y, g, v;
            };
        };
    };
};

struct vec3 {
    union {
        float data[3];
        struct{
            union {
                float x, r;
            };
            union {
                float y, g;
            };
            union {
                float z, b;
            };
        };
    };
};

struct vec4 {
    union {
        float data[4];
        struct{
            union {
                float x, r;
            };
            union {
                float y, g;
            };
            union {
                float z, b;
            };
            union {
                float w, a;
            };
        };
    };
};

OX_API vec2 vec2zero();

OX_API vec3 vec3zero();

OX_API vec4 vec4zero();