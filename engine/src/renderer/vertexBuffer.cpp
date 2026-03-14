#include "vertexbuffer.h"

#include "../includes/vendor.h"

c_vertexBuffer::c_vertexBuffer(vec3 coordinates[4], vec4 color[4], vec2 uvPosition[4]) {
    // assign the given data to the member data struct
    for (int i = 0; i < 4; i++) {
        m_data.vertex[i * 9 + 0] = coordinates[i].x;
        m_data.vertex[i * 9 + 1] = coordinates[i].y;
        m_data.vertex[i * 9 + 2] = coordinates[i].z;
        m_data.vertex[i * 9 + 3] = color[i].r;
        m_data.vertex[i * 9 + 4] = color[i].g;
        m_data.vertex[i * 9 + 5] = color[i].b;
        m_data.vertex[i * 9 + 6] = color[i].a;
        m_data.vertex[i * 9 + 7] = uvPosition[i].u;
        m_data.vertex[i * 9 + 8] = uvPosition[i].v;
    }
    m_data.indices[0] = 0;
    m_data.indices[1] = 1;
    m_data.indices[2] = 2;
    m_data.indices[3] = 0;
    m_data.indices[4] = 2;
    m_data.indices[5] = 3;
}

void c_vertexBuffer::destroy() {
    glDeleteBuffers(1, &m_vertexBufferObject);
    glDeleteBuffers(1, &m_elementBufferObject);
}

void c_vertexBuffer::generate() {
    glGenBuffers(1, &m_vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_data.vertex), m_data.vertex, GL_STATIC_DRAW);

    glGenBuffers(1, &m_elementBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_data.indices), m_data.indices, GL_STATIC_DRAW);
}

s_vertexData c_vertexBuffer::getData() {
    return m_data;
}

void c_vertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
}
void c_vertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}