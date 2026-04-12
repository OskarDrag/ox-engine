#pragma once

#include "../defines.h"

#include "../core/window.h"
#include "../core/camera.h"
#include "../core/math.h"

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "shader.h"
#include "texture.h"

struct s_settingsRenderer {
    std::string shaderPath;
};

struct s_transform {
    vec3 location;
    vec3 rotation;
    vec3 scale;
};

class c_renderer {
    public:
        bool initialise(c_window* window, c_camera* camera);
        void updateFrame();
        void drawQuad(s_transform quadTransform, std::string texturePath);
        void shutdown();
        std::string getShaderPath();
        void setShaderPath(std::string path);
    private:
        c_window* m_windowRef;
        c_camera* m_cameraRef;
        c_vertexBuffer m_buffer;
        c_shader m_shader;
        c_vertexArray m_array;
        std::string m_shaderPath;
        s_settingsRenderer m_settings;
        c_texture m_texture;
        std::vector<std::string> m_usedTextures;
        static int m_quadCount;
};