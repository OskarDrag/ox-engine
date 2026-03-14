#pragma once

#include "vertexBuffer.h"

#include "../defines.h"

class c_vertexArray {
    public:
        OX_API c_vertexArray();
        void destroy();
        void generate();
        void bind();
        void unbind();
        void addAttribute(s_vertexData data, uint size);
    private:
        uint m_vertexArrayObject;
        uint m_attributeID;
        uint m_attributeOffset;
};