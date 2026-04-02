#include "texture.h"

#include "../includes/vendor.h"
#include "../core/log.h"

void textureSystemInitialise() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    stbi_set_flip_vertically_on_load(true);
}

c_texture::c_texture(std::string texturePath) {
    m_path = texturePath;
    int nrOfChannels;
    

    uchar* data = stbi_load(m_path.c_str(), &m_width, &m_height, &nrOfChannels, 0);
    switch (nrOfChannels) {
        case 3:
            m_type = JPG;
            break;
        case 4: 
            m_type = PNG;
            break;
        default:
            break;
    }
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if(data) {
        if (m_type == JPG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        if (m_type == PNG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
    }
    else {
        ox_error("Failed to load texture: ", texturePath);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

c_texture::~c_texture() {
    glDeleteTextures(1, &textureID);
}

void c_texture::bind() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void c_texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}