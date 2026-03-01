#include "application.h"

// entry point to the application

void gameFrame();

extern s_appConfig appConfig;
s_appState appState;

int main() {
    if (startupProgram(&appState, appConfig)) {
        setGameFrameCallback(gameFrame);
        mainLoop();

        shutdownProgram();
        return 0;
    }
    return -1;
}

// often used stuff like this will have the appState prefix deleted and used the ox_ prefix so it will be easier to type

#define ox_input appState.input
