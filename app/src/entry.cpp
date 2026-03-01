#include <entry.h>
#include <application.h>

#include <core/log.h>

// the startup configuration of the app

s_appConfig appConfig = {
    "ox-engine app",  // name
    false,  // fullscreen mode
    // if fullscreen is set to "true" the dimensions will be brought from the monitor
    1080,    // width (px)      
    720     // height (px)      
};

double timeSeconds = 0.0f;

// the main loop of the game is here
void gameFrame() {
    
    if (appState.input.isKeyHeld(KEY_SPACE) && getTimeRunning() > timeSeconds + 1.0f) {
        OX_DEBUG("Time running: ", std::floor(appState.timeRunning), "s");
        timeSeconds = getTimeRunning();
    }
    if (appState.input.scrolled()) {
        OX_DEBUG(appState.input.getScrollDirection());
    }
}
