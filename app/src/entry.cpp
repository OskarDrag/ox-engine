#include <entry.h>
#include <application.h>

#include <core/log.h>

// the startup configuration of the app

s_appConfig appConfig = {
    "test window",  // name
    false,  // fullscreen mode
    1080,    // width (px)
    720     // height (px)
};



// the main loop of the game is here
void gameFrame() {
    if (appState.input.isKeyHeld(KEY_SPACE)) {
        OX_DEBUG("game running . . . ");
    }
}
