#pragma once 

#include "math.h"

#include "../defines.h"

enum axis {
    X, Y, Z,
};

class c_camera {
    public:
        c_camera() = default;
        void create();
        OX_API void move(axis axis, float value);
        OX_API void setLocation(float x, float y, float z);
        OX_API vec3 getLocation();
    private:
};