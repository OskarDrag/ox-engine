#pragma once

union vec2 {
    float elements[2];
    struct {
        union {
            float x, r, u;
        };
        union {
            float y, g, v;
        };
    };
};

union vec3 {
    float elements[3];
    struct {
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

union vec4 {
    float elements[4];
    struct {
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