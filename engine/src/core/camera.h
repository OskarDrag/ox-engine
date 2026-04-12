#pragma once 

#include "math.h"

#include "../defines.h"

enum axis {
    X, Y, Z,
};

enum direction {
    RIGHT, UP, FORWARD
};

class c_camera {
    public:
        void update();
        OX_API void move(direction direction, float value);
        OX_API void moveOnAxis(axis axis, float value);
        OX_API void rotateOnAxis(axis axis, float value);
        OX_API void setLocation(float x, float y, float z);
        OX_API void setRotation(float x, float y, float z);
        OX_API void setFOV(float value);
        OX_API void setMovementSpeed(float value);
        OX_API vec3 getLocation();
        OX_API vec3 getRotation();
        OX_API float getFOV();
        OX_API float getMovementSpeed();
        void getTimeAdress(double* deltaTime);
    private:
        static float m_movementSpeed;
        double* m_deltaTime;
        
};