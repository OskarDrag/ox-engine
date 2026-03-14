#include "shader.h"

#include "../includes/vendor.h"

#include "../core/assert.h"

c_shader::c_shader(const char* vertexSourceCode, const char* fragmentSourceCode) {

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

uint c_shader::getVertexShader() {
    return m_vertexShader;
}

uint c_shader::getFragmentShader() {
    return m_fragmentShader;
}

void c_shader::m_checkShaderStatus(uint shader) {
    int shaderCompilationSucces;
    char log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompilationSucces);
    if (!shaderCompilationSucces) {
        glGetShaderInfoLog(shader, 512, NULL, log);
        ox_assert_message(shaderCompilationSucces, log);
    }
}

void c_shader::m_checkProgramStatus(uint program) {
    int programCompilationSucces;
    char log[512];
    glGetProgramiv(program, GL_LINK_STATUS, &programCompilationSucces);
    if (!programCompilationSucces) {
        glGetProgramInfoLog(program, 512, NULL, log);
        ox_assert_message(programCompilationSucces, log);
    }
}

void c_shader::run() {
    glUseProgram(m_shaderID);
}