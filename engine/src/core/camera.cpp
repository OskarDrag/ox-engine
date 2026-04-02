#include "camera.h"

#include "../includes/vendor.h"

static glm::vec3 cameraPosition = glm::vec3(0.0f);

void c_camera::create() {

}

void c_camera::move(axis axis, float value) {
    switch (axis)
    {
    case X:
        cameraPosition.x -= value;
        break;
    case Y:
        cameraPosition.y -= value;
        break;
    case Z:
        cameraPosition.z += value;
        break;
    default:
        break;
    }
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z));

}

void c_camera::setLocation(float x, float y, float z) {

}

vec3 c_camera::getLocation() {
    return vec3 {
        cameraPosition.x, cameraPosition.y, cameraPosition.z
    };
}