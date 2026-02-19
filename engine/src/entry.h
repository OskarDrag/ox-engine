#include "application.h"

// entry point to the application

extern s_appConfig appConfig;
s_appState appState;

int main() {
    if (startupProgram(&appState, appConfig)) {
        mainLoop(&appState);

        shutdownProgram();
    }
    return 0;
}