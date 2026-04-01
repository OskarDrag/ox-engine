#include "renderer.h"

#include "../includes/vendor.h"

#include "../core/assert.h"

static glm::mat4 model = glm::mat4(1.0f);
static glm::mat4 view = glm::mat4(1.0f);
static glm::mat4 projection;

static vec3 drawPosition[4] = { 
    {0.5f, 0.5f, 0.0f},
    {0.5f, -0.5f, 0.0f},
    {-0.5f, -0.5f, 0.0f},
    {-0.5f, 0.5f, 0.0f},
 };

static vec4 drawColor[4] = {
    vec4one(),
    vec4one(),
    vec4one(),
    vec4one()
 };


static vec2 drawuv[4] = { 
    {1.0f, 1.0f},
    {1.0f, 0.0f},
    {0.0f, 0.0f},
    {0.0f, 1.0f},
 };

bool c_renderer::initialise(c_window* window) {
    m_windowRef = window;

    ox_assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    textureSystemInitialise();

    m_shader = c_shader();
    m_shader.create("vertexShader.glsl", "fragmentShader.glsl", m_settings.shaderPath);
    m_shader.run();

    m_array = c_vertexArray();
    m_array.generate();
    m_array.bind();
    m_buffer = c_vertexBuffer(drawPosition, drawColor, drawuv);
    m_buffer.generate();
    m_buffer.bind();

    m_array.addAttribute(m_buffer.getData(), 3);    // position
    m_array.addAttribute(m_buffer.getData(), 4);    // color
    m_array.addAttribute(m_buffer.getData(), 2);    // uv 

    m_array.unbind();
    return 1;
}

void c_renderer::updateFrame() {
    glClearColor(0.5f, 0.5f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    projection = glm::ortho(-m_windowRef->getAspectRatio(), m_windowRef->getAspectRatio(), -1.0f, 1.0f, -100.0f, 100.0f);

    m_shader.run();
    m_shader.setMat4("model", glm::value_ptr(model));
    m_shader.setMat4("view", glm::value_ptr(view));
    m_shader.setMat4("projection", glm::value_ptr(projection));

    c_texture tex("data/test/textures/Lawliet L.jpg");
    tex.bind();
    m_array.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(m_windowRef->instance);
}

void c_renderer::shutdown() {
    m_shader.destroy();
    m_array.destroy();
    m_buffer.destroy();
}

std::string c_renderer::getShaderPath() {
    return m_settings.shaderPath;
}

void c_renderer::setShaderPath(std::string path) {
    m_settings.shaderPath = path;
}