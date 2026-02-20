#pragma once

#include <string>

#include "defines.h"
#include "includes/vendor.h"
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
    float timeRunning;
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

OX_API void mainLoop(s_appState* appState);

OX_API void shutdownProgram(s_appState* appState);

OX_API void abortProgram();