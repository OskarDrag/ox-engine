#pragma once

#include <string>

#include "defines.h"
#include "core/window.h"
#include "core/input.h"

enum e_platform {
    windows32   = 0,
    windows64   = 1,
    linux       = 2,
    unix        = 3,
    mac         = 4,
};

struct s_appState {
    std::string name;
    bool isRunning;
    double timeRunning;
    e_platform platform;
    c_window window;
    c_input input;
};

struct s_appConfig {
    std::string name;
    bool fullscreen;
    uint width;
    uint height;
};

OX_API bool startupProgram(s_appState* appState, s_appConfig appConfig);

OX_API void setGameFrameCallback(void (*callback)());

OX_API void mainLoop();

OX_API void shutdownProgram();

OX_API double getTimeRunning();