#define ENTRY_POINT
#include <ox.h>

vec2 mousePositionPrevious;

// the main loop of the game is here
void gameFrame() {
    // movement speed
    if (ox_input.isButtonHeld(RMB)) {
        ox_cam.setMovementSpeed((ox_cam.getMovementSpeed() - 0.001f));
    }
    if (ox_input.isButtonHeld(LMB)) {
        ox_cam.setMovementSpeed((ox_cam.getMovementSpeed() + 0.001f));
    }

    // movement input
    if (ox_input.isKeyHeld(KEY_UP) || ox_input.isKeyHeld(KEY_W)) {
        ox_cam.move(FORWARD, ox_cam.getMovementSpeed());
    }
    if (ox_input.isKeyHeld(KEY_DOWN) || ox_input.isKeyHeld(KEY_S)) {
        ox_cam.move(FORWARD, -ox_cam.getMovementSpeed());
    }
    if (ox_input.isKeyHeld(KEY_RIGHT) || ox_input.isKeyHeld(KEY_D)) {
        ox_cam.move(RIGHT, ox_cam.getMovementSpeed());
    }
    if (ox_input.isKeyHeld(KEY_LEFT) || ox_input.isKeyHeld(KEY_A)) {
        ox_cam.move(RIGHT, -ox_cam.getMovementSpeed());
    }
    if (ox_input.isKeyHeld(KEY_LEFT_SHIFT) || ox_input.isKeyHeld(KEY_E)) {
        ox_cam.move(UP, ox_cam.getMovementSpeed());
    }
    if (ox_input.isKeyHeld(KEY_LEFT_CONTROL) || ox_input.isKeyHeld(KEY_Q)) {
        ox_cam.move(UP, -ox_cam.getMovementSpeed());
    }

    // fov
    if (ox_input.scrolled()) {
        ox_cam.setFOV(ox_cam.getFOV() - ox_input.getScrollDirection());
    }

    // camera rotation
    vec2 mousePosition = ox_input.getMousePosition();
    vec2 mouseDelta = { mousePosition.x - mousePositionPrevious.x, mousePosition.y - mousePositionPrevious.y};
    mousePositionPrevious = mousePosition;
    ox_cam.rotateOnAxis(X, -mouseDelta.y);
    ox_cam.rotateOnAxis(Y, -mouseDelta.x);
}