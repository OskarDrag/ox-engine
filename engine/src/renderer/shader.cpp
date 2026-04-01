#include "shader.h"

#include "../includes/vendor.h"

#include "../core/assert.h"
#include "../core/log.h"

std::string c_shader::m_shadersPath = "";

void c_shader::create(const char *vertexSourceFileName, const char *fragmentSourceFileName, std::string path) {

    m_shadersPath = path;

    std::string vertexCode, fragmentCode;
    std::string vertexPath = m_shadersPath + vertexSourceFileName;
    std::string fragmentPath = m_shadersPath + fragmentSourceFileName;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;

    vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);
        std::stringstream vertexStream, fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();
    }
    catch (std::ifstream::failure& e) {
        ox_warn("shader read unsuccesfully", e.what());
    }

    const char* vertexSourceCode = vertexCode.c_str();
    const char* fragmentSourceCode = fragmentCode.c_str();

    m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertexShader, 1, &vertexSourceCode, NULL);
    glCompileShader(m_vertexShader);
    m_checkShaderStatus(m_vertexShader);

    m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragmentShader, 1, &fragmentSourceCode, NULL);
    glCompileShader(m_fragmentShader);
    m_checkShaderStatus(m_fragmentShader);

    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, m_vertexShader);
    glAttachShader(m_shaderID, m_fragmentShader);
    glLinkProgram(m_shaderID);
}

void c_shader::m_checkShaderStatus(uint shader) {
    int shaderCompilationSucces;
    char output[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompilationSucces);
    if (!shaderCompilationSucces) {
        glGetShaderInfoLog(shader, 512, NULL, output);
        ox_warn(output);
    }
}

void c_shader::m_checkProgramStatus(uint program) {
    int programCompilationSucces;
    char output[512];
    glGetProgramiv(program, GL_LINK_STATUS, &programCompilationSucces);
    if (!programCompilationSucces) {
        glGetProgramInfoLog(program, 512, NULL, output);
        ox_warn(output);
    }
}

void c_shader::run() {
    glUseProgram(m_shaderID);
}

void c_shader::destroy() {
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
}

void c_shader::setBool(const std::string name, bool value) {
    glUniform1i(glGetUniformLocation(m_shaderID, name.c_str()), (int)value);
}

void c_shader::setInt(const std::string name, int value) {
    glUniform1i(glGetUniformLocation(m_shaderID, name.c_str()), value);
}

void c_shader::setFloat(const std::string name, float value) {
    glUniform1f(glGetUniformLocation(m_shaderID, name.c_str()), value);
}

void c_shader::setVec2(const std::string name, float x, float y) {
    glUniform2f(glGetUniformLocation(m_shaderID, name.c_str()), x, y);
}

void c_shader::setVec3(const std::string name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(m_shaderID, name.c_str()), x, y, z);
}

void c_shader::setVec4(const std::string name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(m_shaderID, name.c_str()), x, y, z, w);
}

void c_shader::setMat2(const std::string name, float *value) {
    glUniformMatrix2fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, 0, value);
}

void c_shader::setMat3(const std::string name, float *value) {
    glUniformMatrix3fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, 0, value);
}

void c_shader::setMat4(const std::string name, float *value) {
    glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, 0, value);
}