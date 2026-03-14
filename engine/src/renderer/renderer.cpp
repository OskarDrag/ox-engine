#include "renderer.h"

#include "../includes/vendor.h"

#include "../core/assert.h"

static vec3 drawPosition[4] = { 
    {0.5f, 0.5f, 0.0f},
    {0.5f, -0.5f, 0.0f},
    {-0.5f, -0.5f, 0.0f},
    {-0.5f, 0.5f, 0.0f},
 };

 static vec4 drawColor[4] = { 
    {0.5f, 0.5f, 0.0f, 1.0f},
    {0.5f, -0.5f, 0.0f, 1.0f},
    {-0.5f, -0.5f, 0.0f, 1.0f},
    {-0.5f, 0.5f, 0.0f, 1.0f},
 };

 static vec2 drawuv[4] = { 
    {1.0f, 1.0f},
    {1.0f, 0.0f},
    {0.0f, 0.0f},
    {0.0f, 1.0f},
 };


static const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec4 aColor;\n"
    "layout (location = 2) in vec2 aUV;\n"

    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

static const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

bool c_renderer::initialise(c_window* window) {
    m_windowRef = window;

    ox_assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    m_shader = c_shader(vertexShaderSource, fragmentShaderSource);
    m_shader.run();

    m_array = c_vertexArray();
    m_array.generate();
    m_array.bind();
    m_buffer = c_vertexBuffer(drawPosition, drawColor, drawuv);
    m_buffer.generate();
    m_buffer.bind();

    m_array.addAttribute(m_buffer.getData(), 3);    // position
    m_array.addAttribute(m_buffer.getData(), 4);    // color
    m_array.addAttribute(m_buffer.getData(), 2);    // uv coordinates

    

    m_array.unbind();
    return 1;
}

void c_renderer::updateFrame() {
    glClearColor(0.5f, 0.5f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_shader.run();
    m_array.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(m_windowRef->instance);
}

void c_renderer::shutdown() {
    glDeleteShader(m_shader.getVertexShader());
    glDeleteShader(m_shader.getFragmentShader());
    m_array.destroy();
    m_buffer.destroy();
}
