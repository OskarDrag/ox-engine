#include "application.h"

#include "core/log.h"
#include "core/assert.h"
#include "core/window.h"

static void (*gameFrameCallback)() = nullptr;

bool startupProgram(s_appState* appState, s_appConfig appConfig) {

    // setting up the application on the start

    appState->name = appConfig.name;
    appState->isRunning = true;
    appState->timeRunning = 0.0f;
    #ifdef OS_WINDOWS_32
    appState->platform = windows32;
    #elif OS_WINDOWS_64
    appState->platform = windows64;
    #elif OS_LINUX
    appState->platform = linux;
    #elif OS_UNIX
    appState->platform = unix;
    #elif OS_MAC
    appState->platform = mac;
    #endif

    // starting all the subsystems
    OX_ASSERT(initializeLogger()); // logger gets to start before the call so it will input it into the log file
    OX_INFO("starting the application . . . ");
    OX_INFO("initialising subsystems . . . ");



    OX_INFO("initialising succesfull");

    // opening glfw library
    OX_ASSERT(glfwInit());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef OS_MAC
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    // creating the window
    appState->window = c_window(appConfig.name, appConfig.fullscreen, appConfig.width, appConfig.height);
    appState->input = c_input(appState->window.instance);
    //OX_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    OX_INFO("application opened succesfully!");

    return 1;
}

void setGameFrameCallback(void (*callback)()) {
    gameFrameCallback = callback;
}

void mainLoop(s_appState* appState) {
    while (appState->isRunning) {
        glfwSwapBuffers(appState->window.instance);
        // all input should be done between update and reset
        appState->input.update();
        if (appState->input.isKeyPressed(KEY_ESCAPE)) {
            appState->isRunning = false;
        }
        if (appState->input.isButtonHeld(RMB)) {
            glm::vec2 pos = appState->input.getMousePosition();
            OX_DEBUG(pos.x, pos.y);
        }
        if (appState->input.isKeyHeld(KEY_LEFT_CONTROL)) {
            OX_DEBUG(appState->input.getScrollOffset());
        }

        OX_ASSERT(gameFrameCallback) gameFrameCallback();

        appState->input.resetInput();
        if (glfwWindowShouldClose(appState->window.instance)) appState->isRunning = false;
    }
}


void shutdownProgram(s_appState* appState) {
    OX_INFO("closing the app");
    appState->input.shutdown();
    glfwTerminate();
    shutdownLogger();
}

void abortProgram() {
    OX_INFO("aborting the application");
    exit(0);
}