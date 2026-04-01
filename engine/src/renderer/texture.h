#pragma once

#include "../defines.h"

enum textureType {
    JPG,
    PNG
};

void textureSystemInitialise();

class c_texture {
    public:
        c_texture() = default;
        c_texture(std::string texturePath);
        ~c_texture();
        void bind();
        void unbind();
    private:
        uint textureID;
        std::string m_path;
        int m_height;
        int m_width;
        textureType m_type;
};