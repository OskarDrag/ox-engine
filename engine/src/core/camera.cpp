#include "camera.h"

#include "../includes/vendor.h"
#include "log.h"

static vec3 cameraPosition = {0.0f, 0.0f, 0.0f};
static vec3 cameraRotation = {0.0f, 0.0f, 0.0f};

static const glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
static const glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

static glm::vec3 cameraDirection;

static glm::vec3 cameraRight;
static glm::vec3 cameraUp;
static glm::vec3 cameraForward;

static float cameraFOV = 90.0f;
float c_camera::m_movementSpeed = 0.01f;


void c_camera::update() {
    glm::vec3 pos = glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z);
    glm::vec3 dir;
    dir.x = sin(glm::radians(cameraRotation.y)) * cos(glm::radians(cameraRotation.x));
    dir.y = sin(glm::radians(cameraRotation.x));
    dir.z = cos(glm::radians(cameraRotation.y)) * cos(glm::radians(cameraRotation.x));
    
    cameraDirection = glm::normalize(dir);
    cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    cameraUp = glm::normalize(glm::cross(cameraDirection, cameraRight));
    cameraForward = cameraDirection;
}

void c_camera::moveOnAxis(axis axis, float value) {
    switch (axis)
    {
    case X:
        cameraPosition.x -= value * *m_deltaTime;
        break;
    case Y:
        cameraPosition.y -= value * *m_deltaTime;
        break;
    case Z:
        cameraPosition.z += value * *m_deltaTime;
        break;
    default:
        break;
    }
}

void c_camera::move(direction direction, float value) {
    switch (direction) {
        case RIGHT:
            cameraPosition.x -= cameraRight.x * value * *m_deltaTime;
            cameraPosition.y -= cameraRight.y * value * *m_deltaTime;
            cameraPosition.z += cameraRight.z * value * *m_deltaTime;
            break;
        case UP:
            cameraPosition.x += cameraUp.x * value * *m_deltaTime;
            cameraPosition.y -= cameraUp.y * value * *m_deltaTime;
            cameraPosition.z -= cameraUp.z * value * *m_deltaTime;
            break;
        case FORWARD:
            cameraPosition.x -= cameraForward.x * value * *m_deltaTime;
            cameraPosition.y += cameraForward.y * value * *m_deltaTime;
            cameraPosition.z += cameraForward.z * value * *m_deltaTime;
            break;
        default:
            break;
    }
}

void c_camera::rotateOnAxis(axis axis, float value) {
    switch (axis)
    {
    case X:
        cameraRotation.x -= value;
        break;
    case Y:
        cameraRotation.y -= value;
        break;
    case Z:
        cameraRotation.z += value;
        break;
    default:
        break;
    }

    if(cameraRotation.x > 89.0f)
    cameraRotation.x =  89.0f;
    if(cameraRotation.x < -89.0f)
    cameraRotation.x = -89.0f;

}

void c_camera::setLocation(float x, float y, float z) {
    cameraPosition = {x, y, z};
}

void c_camera::setRotation(float x, float y, float z) {
    cameraRotation = {x, y, z};
}

void c_camera::setFOV(float value) {
    if (value > 179) {
        cameraFOV = 179;
        return;
    }
    if (value < 1) {
        cameraFOV = 1;
        return;
    }
    cameraFOV = value;
}

void c_camera::setMovementSpeed(float value) {
    if (value < 0) {
        m_movementSpeed = 0;
        return;
    }
    m_movementSpeed = value;
}

vec3 c_camera::getLocation() {
    return vec3 {
        cameraPosition.x, cameraPosition.y, cameraPosition.z
    };
}

vec3 c_camera::getRotation() {
    return vec3 {
        cameraRotation.x, cameraRotation.y, cameraRotation.z
    };
}

float c_camera::getFOV() {
    return cameraFOV;
}

float c_camera::getMovementSpeed() {
    return m_movementSpeed;
}

void c_camera::getTimeAdress(double* deltaTime) {
    m_deltaTime = deltaTime;
}