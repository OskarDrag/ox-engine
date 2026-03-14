#pragma once

#include "../core/math.h"
#include "../defines.h"

struct s_vertexData {
    float vertex[36];
    uint indices[6];
};

class c_vertexBuffer {
    public:
        c_vertexBuffer() = default;
        OX_API c_vertexBuffer(vec3 coordinates[4], vec4 color[4], vec2 uvPosition[4]);
        void destroy();
        void generate();
        s_vertexData getData();
        void bind();
        void unbind();
        
    private:
        s_vertexData m_data;
        uint m_vertexBufferObject;
        uint m_elementBufferObject;
};