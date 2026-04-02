#pragma once

#include "application.h"
#include "defines.h"

// entry point to the application

extern s_appConfig appConfig;

#ifdef ENTRY_POINT

s_appState appState;

void gameFrame();

int main() {
    if (startupProgram(&appState, appConfig)) {
        setGameFrameCallback(gameFrame);
        mainLoop();

        shutdownProgram();
        return 0;
    }
    return -1;
}

#endif

// often used stuff like this will have the appState prefix deleted and used the ox_ prefix so it will be easier to type
#define ox_input appState.input
#define ox_cam appState.camera