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