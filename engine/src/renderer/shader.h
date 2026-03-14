#pragma once 

#include "../defines.h"

class c_shader {
    public:
        c_shader() = default;
        c_shader(const char* vertexSourceCode, const char* fragmentSourceCode);
        void run();
        uint getVertexShader();
        uint getFragmentShader();
    private:
        uint m_shaderID;
        uint m_vertexShader;
        uint m_fragmentShader;
        void m_checkShaderStatus(uint shader);
        void m_checkProgramStatus(uint program);
};