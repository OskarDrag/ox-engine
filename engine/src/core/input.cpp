#include "input.h"

#include <algorithm>
#include "log.h"



glm::vec2 c_input::m_mousePosition = glm::vec2(0.0f, 0.0f);
float c_input::m_scrollOffset = 0.0f;
float c_input::m_oldScrollOffset = c_input::m_scrollOffset;

std::vector<int> c_input::m_pressedKeys;
std::vector<int> c_input::m_releasedKeys;
std::vector<int> c_input::m_heldKeys;

std::vector<int> c_input::m_pressedButtons;
std::vector<int> c_input::m_releasedButtons;
std::vector<int> c_input::m_heldButtons;

c_input::c_input(GLFWwindow* window) {

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
}

void c_input::shutdown() {

}

void c_input::update() {
    glfwPollEvents();
    
}

void c_input::resetInput() {
    m_pressedKeys.clear();
    m_releasedKeys.clear();
    m_pressedButtons.clear();
    m_releasedButtons.clear();
    m_oldScrollOffset = m_scrollOffset;
}

void c_input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == PRESSED) {
        OX_INFO(key, "pressed");
        if (std::find(m_pressedKeys.begin(), m_pressedKeys.end(), key) == m_pressedKeys.end()) {
            m_pressedKeys.push_back(key);
            m_heldKeys.push_back(key);
        }
    }
    if (action == RELEASED) {
        OX_INFO(key, "released");
        std::vector<int>::iterator iterator = std::find(m_heldKeys.begin(), m_heldKeys.end(), key);
        if (iterator != m_heldKeys.end()) {
            m_heldKeys.erase(iterator);
        }
        m_releasedKeys.push_back(key);
    }
}

void c_input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == PRESSED) {
        OX_INFO(button, "pressed");
        if (std::find(m_pressedButtons.begin(), m_pressedButtons.end(), button) == m_pressedButtons.end()) {
            m_pressedButtons.push_back(button);
            m_heldButtons.push_back(button);
        }
    }
    if (action == RELEASED) {
        OX_INFO(button, "released");
        std::vector<int>::iterator iterator = std::find(m_heldButtons.begin(), m_heldButtons.end(), button);
        if (iterator != m_heldButtons.end()) {
            m_heldButtons.erase(iterator);
        }
        m_releasedButtons.push_back(button);
    }   
}

void c_input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    m_mousePosition = glm::vec2(xpos, ypos);
}

void c_input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    m_scrollOffset += (float)yoffset;
}

std::vector<int> c_input::getHeldKeys() {
    return m_heldKeys;
}

std::vector<int> c_input::getHeldButtons() {
    return m_heldButtons;
}

glm::vec2 c_input::getMousePosition() {
    return m_mousePosition;
}

float c_input::getScrollOffset() {
    return m_scrollOffset;
}

void c_input::setScrollOffset(float offset) {
    m_scrollOffset = offset;
}

bool c_input::isKeyPressed(int key) {
    if (std::find(m_pressedKeys.begin(), m_pressedKeys.end(), key) != m_pressedKeys.end()) {
        return 1;
    }
    return 0;
}

bool c_input::isKeyReleased(int key) {
    if (std::find(m_releasedKeys.begin(), m_releasedKeys.end(), key) != m_releasedKeys.end()) {
        return 1;
    }
    return 0;
}

bool c_input::isKeyHeld(int key) {
    if (std::find(m_heldKeys.begin(), m_heldKeys.end(), key) != m_heldKeys.end()) {
        return 1;
    }
    return 0;
}

bool c_input::isButtonPressed(int button) {
    if (std::find(m_pressedButtons.begin(), m_pressedButtons.end(), button) != m_pressedButtons.end()) {
        return 1;
    }
    return 0;
}

bool c_input::isButtonReleased(int button) {
    if (std::find(m_releasedButtons.begin(), m_releasedButtons.end(), button) != m_releasedButtons.end()) {
        return 1;
    }
    return 0;
}

bool c_input::isButtonHeld(int button) {
    if (std::find(m_heldButtons.begin(), m_heldButtons.end(), button) != m_heldButtons.end()) {
        return 1;
    }
    return 0;
}

bool c_input::scrolled() {
    if (m_scrollOffset != m_oldScrollOffset) {
        return 1;
    }
    return 0;
}

float c_input::getScrollDirection() {
    if (m_scrollOffset != m_oldScrollOffset) {
        if (m_scrollOffset < m_oldScrollOffset) {
            return -1;
        }
        if (m_scrollOffset > m_oldScrollOffset) {
            return 1;
        }
    }
    return 0;
}