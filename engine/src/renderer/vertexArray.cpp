#include "vertexArray.h"

#include "../includes/vendor.h"

c_vertexArray::c_vertexArray() {
    
    m_attributeID = 0;
    m_attributeOffset = 0;
}

void c_vertexArray::destroy() {
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void c_vertexArray::generate() {
    glGenVertexArrays(1, &m_vertexArrayObject);
}

void c_vertexArray::bind() {
    glBindVertexArray(m_vertexArrayObject);
}
void c_vertexArray::unbind() {
    glBindVertexArray(0);
}

void c_vertexArray::addAttribute(s_vertexData data, uint size) {
    glVertexAttribPointer  (m_attributeID,
                            size,
                            GL_FLOAT,
                            GL_FALSE,
                            sizeof(data.vertex) / 4,
                            (void*) (m_attributeOffset * sizeof(float))
                            );
    glEnableVertexAttribArray(m_attributeID);
    m_attributeID++;
    m_attributeOffset += size;
}