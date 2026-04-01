#pragma once

#include "../defines.h"

#include "../core/window.h"

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "shader.h"
#include "texture.h"

struct s_settingsRenderer {
    std::string shaderPath;
};

class c_renderer {
    public:
        bool initialise(c_window* window);
        void updateFrame();
        void shutdown();
        std::string getShaderPath();
        void setShaderPath(std::string path);
    private:
        c_window* m_windowRef;
        c_vertexBuffer m_buffer;
        c_shader m_shader;
        c_vertexArray m_array;
        std::string m_shaderPath;
        s_settingsRenderer m_settings;
};