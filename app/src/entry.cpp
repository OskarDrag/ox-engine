#define ENTRY_POINT
#include <ox.h>

// the main loop of the game is here
void gameFrame() {
    if (ox_input.isKeyHeld(KEY_UP) || ox_input.isKeyHeld(KEY_W)) {
        ox_cam.move(Z, 0.01f);
    }
    if (ox_input.isKeyHeld(KEY_DOWN) || ox_input.isKeyHeld(KEY_S)) {
        ox_cam.move(Z, -0.01f);
    }
    if (ox_input.isKeyHeld(KEY_RIGHT) || ox_input.isKeyHeld(KEY_D)) {
        ox_cam.move(X, 0.01f);
    }
    if (ox_input.isKeyHeld(KEY_LEFT) || ox_input.isKeyHeld(KEY_A)) {
        ox_cam.move(X, -0.01f);
    }
    if (ox_input.isKeyHeld(KEY_LEFT_SHIFT) || ox_input.isKeyHeld(KEY_E)) {
        ox_cam.move(Y, 0.01f);
    }
    if (ox_input.isKeyHeld(KEY_LEFT_CONTROL) || ox_input.isKeyHeld(KEY_Q)) {
        ox_cam.move(Y, -0.01f);
    }
}