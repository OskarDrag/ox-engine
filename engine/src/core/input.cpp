#include "input.h"

#include <algorithm>
#include "log.h"


std::vector<int> c_input::m_pressedKeys;
std::vector<int> c_input::m_releasedKeys;
std::vector<int> c_input::m_heldKeys;

c_input::c_input(GLFWwindow* window) {

    glfwSetKeyCallback(window, key_callback);
}

void c_input::shutdown() {

}

void c_input::update() {
    glfwPollEvents();
    resetKeys();
}

void c_input::resetKeys() {
    m_pressedKeys.clear();
    m_releasedKeys.clear();
}

void c_input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == KEY_PRESSED) {
        OX_INFO(key, "pressed");
        if(std::find(m_pressedKeys.begin(), m_pressedKeys.end(), key) != m_pressedKeys.end())
            OX_DEBUG(key, "is already pressed");
        else {
        m_pressedKeys.push_back(key);
        m_heldKeys.push_back(key);
        }
    }
    
}