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
    glfwSetFramebufferSizeCallback(instance, framebuffer_size_callback);  
}

float c_window::getAspectRatio() {
    int x, y;
    x = width;
    y = height;
    glfwGetFramebufferSize(instance, &x, &y);
    return (float)x / (float)y;
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  