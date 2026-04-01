#define ENTRY_POINT
#include <ox.h>

#include "func.h"


// the main loop of the game is here
void gameFrame() {
    if (ox_input.isKeyPressed(KEY_SPACE)) {
        printText("Space pressed");
    }
    if (ox_input.scrolled()) {
        printText(std::to_string(ox_input.getScrollDirection()));
    }
}