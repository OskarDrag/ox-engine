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

bool c_renderer::initialise(c_window* window, c_camera* camera) {
    m_windowRef = window;
    m_cameraRef = camera;

    ox_assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    //projection = glm::ortho(-m_windowRef->getAspectRatio(), m_windowRef->getAspectRatio(), -1.0f, 1.0f, -100.0f, 100.0f);

    projection = glm::perspective(glm::radians(m_cameraRef->getFOV()), m_windowRef->getAspectRatio(), 0.01f, 100.0f);
    m_shader.setMat4("projection", glm::value_ptr(projection));

    vec3 cameraPosition = m_cameraRef->getLocation();
    vec3 cameraRotation = m_cameraRef->getRotation();
    view = glm::mat4(1.0f);
    view = glm::rotate(view, glm::radians(cameraRotation.x),glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, glm::radians(cameraRotation.y),glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::rotate(view, glm::radians(cameraRotation.z),glm::vec3(0.0f, 0.0f, 1.0f));
    view = glm::translate(view, glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z));
    
    m_shader.setMat4("view", glm::value_ptr(view));

    m_shader.run();
    
    c_texture texture("data/test/textures/Texture 1.jpg");
    texture.bind();
    m_array.bind();

    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.5f));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -0.5f));
    model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    model = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.5f, 0.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.5f, 0.0f));
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    m_shader.setMat4("model", glm::value_ptr(model));
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