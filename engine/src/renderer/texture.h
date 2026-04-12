#pragma once

#include "../defines.h"

enum textureType {
    JPG,
    PNG
};

class c_texture {
    public:
        OX_API c_texture();
        bool create(std::string path);
        OX_API ~c_texture();
        void bind();
        void unbind();
    private:
        uint textureID;
        std::string m_path;
        int m_height;
        int m_width;
        textureType m_type;
};