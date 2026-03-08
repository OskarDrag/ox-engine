#include "window.h"

#include "assert.h"
#include "log.h"

#include "../includes/vendor.h"

c_window::c_window(std::string windowName, bool fullscreenMode, uint windowWidth, uint windowHeight) {
    name = windowName;
    fullscreen = fullscreenMode;
    width = windowWidth;
    height = windowHeight; 

    monitor = glfwGetPrimaryMonitor();
    {
        int monitorX, monitorY;
        glfwGetMonitorWorkarea(monitor, NULL, NULL, &monitorX, &monitorY);
        screenWidth = (uint)monitorX;
        screenHeight = (uint)monitorY;
    }
    
    ox_assert(m_create());
}

float c_window::getAspectRatio() {
    if (fullscreen == true) {
        return screenWidth / screenHeight;
    }
    return width / height;
}

bool c_window::m_create() {
    if (fullscreen) {
        instance = glfwCreateWindow(screenWidth, screenHeight, name.c_str(), monitor, NULL);
    } else {
        instance = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    }
    ox_assert(instance);
    glfwMakeContextCurrent(instance);
    return 1;
}