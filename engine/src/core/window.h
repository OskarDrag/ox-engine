#pragma once

#include "../includes/vendor.h"
#include "../defines.h"

#include <string>


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
        float aspectRatio;
    private:
        bool m_create();
};