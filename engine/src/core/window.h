#pragma once

#include "../defines.h"

struct GLFWwindow;
struct GLFWmonitor;

class c_window {
    public:
        c_window() = default;
        c_window(std::string windowName, bool fullscreenMode, uint windowWidth, uint windowHeight);
        GLFWwindow* instance;
        GLFWmonitor* monitor;
        std::string name;
        bool fullscreen;
        uint width;
        uint height;
        uint screenWidth;
        uint screenHeight;
        float getAspectRatio();
    private:
        bool m_create();
};