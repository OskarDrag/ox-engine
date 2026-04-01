#pragma once 

#include "../defines.h"

class c_shader {
    public:
        void create(const char *vertexSourceFileName, const char *fragmentSourceFileName, std::string path);
        void run();
        void destroy();
        void setBool(const std::string name, bool value);
        void setInt(const std::string name, int value);
        void setFloat(const std::string name, float value);
        void setVec2(const std::string name, float x, float y);
        void setVec3(const std::string name, float x, float y, float z);
        void setVec4(const std::string name, float x, float y, float z, float w);
        void setMat2(const std::string name, float *value);
        void setMat3(const std::string name, float *value);
        void setMat4(const std::string name, float *value);
    private:
        uint m_shaderID;
        uint m_vertexShader;
        uint m_fragmentShader;
        void m_checkShaderStatus(uint shader);
        void m_checkProgramStatus(uint program);
        static std::string m_shadersPath;
};