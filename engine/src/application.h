#pragma once

#include "defines.h"
#include "core/window.h"
#include "core/input.h"
#include "core/camera.h"
#include "core/time.h"
#include "renderer/renderer.h"


enum e_platform {
    windows32   = 0,
    windows64   = 1,
    linux       = 2,
    unix        = 3,
    mac         = 4,
};

enum e_layer {
    LAYER_L,
    LAYER_EMPTY
};

struct s_settings {
    s_settingsRenderer renderer;
};

struct s_appState {
    std::string name;
    bool isRunning;
    s_time time;
    e_platform platform;
    c_window window;
    c_renderer renderer;
    c_input input;
    c_camera camera;
    s_settings settings;
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