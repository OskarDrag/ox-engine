#include "window.h"

#include "assert.h"
#include "log.h"


c_window::c_window(std::string windowName, bool fullscreenMode, uint windowWidth, uint windowHeight) {
    name = windowName;
    fullscreen = fullscreenMode;
    width = windowWidth;
    height = windowHeight; 
    
    OX_ASSERT(m_create());
}

bool c_window::m_create() {
    monitor = glfwGetPrimaryMonitor();
    {
        int monitorX, monitorY;
        glfwGetMonitorWorkarea(monitor, NULL, NULL, &monitorX, &monitorY);
        screenWidth = (uint)monitorX;
        screenHeight = (uint)monitorY;
    }
    
    if (fullscreen) {
        instance = glfwCreateWindow(screenWidth, screenHeight, name.c_str(), monitor, NULL);
    } else {
        instance = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    }
    OX_ASSERT(instance);
    glfwMakeContextCurrent(instance);
    return 1;
}