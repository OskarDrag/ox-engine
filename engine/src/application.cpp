#include "application.h"

#include "includes/vendor.h"

#include "core/log.h"
#include "core/assert.h"
#include "core/window.h"




static void (*gameFrameCallback)() = nullptr;
static s_appState* appRef;

bool startupProgram(s_appState* appState, s_appConfig appConfig) {

    // setting up the application on the start
    appRef = appState;
    appRef->name = appConfig.name;
    appRef->isRunning = true;
    appRef->timeRunning = 0.0f;
    #ifdef OS_WINDOWS_32
    appRef->platform = windows32;
    #elif OS_WINDOWS_64
    appRef->platform = windows64;
    #elif OS_LINUX
    appRef->platform = linux;
    #elif OS_UNIX
    appRef->platform = unix;
    #elif OS_MAC
    appRef->platform = mac;
    #endif

    // starting all the subsystems
    ox_assert(initializeLogger()); // logger gets to start before the call so it will input it into the log file
    ox_info("starting the application . . . ");
    ox_info("initialising subsystems . . . ");



    ox_info("initialising succesfull");

    // opening glfw library
    ox_assert(glfwInit());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (appRef->platform == mac) {
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }
    
    appRef->window = c_window(appConfig.name, appConfig.fullscreen, appConfig.width, appConfig.height);
    appRef->input = c_input(appState->window.instance);
    ox_assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    ox_info("application opened succesfully!");

    return 1;       
}

void setGameFrameCallback(void (*callback)()) {
    gameFrameCallback = callback;
}

void mainLoop() {
    while (appRef->isRunning) {
        appRef->timeRunning = getTimeRunning();
        glfwSwapBuffers(appRef->window.instance);
        // all input should be done between update and reset
        appRef->input.update();
        if (appRef->input.isKeyPressed(KEY_ESCAPE)) {
            appRef->isRunning = false;
        }
        // running the application side code
        ox_assert(gameFrameCallback) gameFrameCallback();

        appRef->input.resetInput();
        if (glfwWindowShouldClose(appRef->window.instance)) appRef->isRunning = false;

        // fps stabiliser (zmienic to na wlasny system czasowy)
        std::this_thread::sleep_for(std::chrono::nanoseconds(1666667));
        
    }
}

void shutdownProgram() {
    ox_info("closing the app");
    appRef->input.shutdown();
    glfwTerminate();
    shutdownLogger();
}

double getTimeRunning() {
    return appRef->timeRunning = glfwGetTime();
}