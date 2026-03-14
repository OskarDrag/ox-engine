#pragma once

#include "../defines.h"

#include "../core/window.h"

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "shader.h"

class c_renderer {
    public:
        bool initialise(c_window* window);
        void updateFrame();
        void shutdown();
    private:
        c_window* m_windowRef;
        c_vertexBuffer m_buffer;
        c_shader m_shader;
        c_vertexArray m_array;
};