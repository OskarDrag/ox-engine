#include <ox.h>

// the startup configuration of the app
// TODO: make this be read from a file so it can be saved and remembered next launch

s_appConfig appConfig = {
    "ox-engine app",  // name
    false,  // fullscreen mode
    // if fullscreen is set to "true" the dimensions will be brought from the monitor
    1080,    // width (px)      
    720     // height (px)      
};

double timeSeconds = 0.0f;
int fps = 0;
vec2 veca = { 3.0f, 4.0f};

// the main loop of the game is here
void gameFrame() {
    
    if (getTimeRunning() > timeSeconds + 1.0f) {
        OX_DEBUG("Time running: ", (int)getTimeRunning(), "s");
        OX_DEBUG(fps, "fps");
        fps = 0;
        timeSeconds = getTimeRunning();
        OX_DEBUG(v2normalised(veca).x, v2normalised(veca).y);
    }
    if (ox_input.scrolled()) {
        OX_DEBUG(ox_input.getScrollDirection());
    }
    fps++;
}