#include "application.h"

#include "core/log.h"
#include "core/assert.h"
#include "core/window.h"


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
    //OX_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    OX_INFO("application opened succesfully!");

    return 1;
}

void mainLoop(s_appState* appState) {
    while (appState->isRunning) {
        glfwSwapBuffers(appState->window.instance);
        
        glfwPollEvents();
        if (glfwWindowShouldClose(appState->window.instance)) appState->isRunning = false;
    }
}

void shutdownProgram() {
    OX_INFO("closing the app");
    glfwTerminate();
    shutdownLogger();
}
