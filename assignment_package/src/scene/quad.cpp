#include "quad.h"

Quad::~Quad()
{}


void Quad::createVBOdata()
{
    GLuint idx[6]{0, 1, 2, 0, 2, 3};
    glm::vec4 vert_pos[4] {glm::vec4(-1.f, -1.f, 1.f, 1.f),
                          glm::vec4(1.f, -1.f, 1.f, 1.f),
                          glm::vec4(1.f, 1.f, 1.f, 1.f),
                          glm::vec4(-1.f, 1.f, 1.f, 1.f)};

    glm::vec2 vert_UV[4] {glm::vec2(0.f, 0.f),
                         glm::vec2(1.f, 0.f),
                         glm::vec2(1.f, 1.f),
                         glm::vec2(0.f, 1.f)};

    m_countOpq = 6;

    generateIdxOpq();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufIdxOpq);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), idx, GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, m_bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), vert_pos, GL_STATIC_DRAW);

    generateUV();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, m_bufUV);
    mp_context->glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec2), vert_UV, GL_STATIC_DRAW);
}


GLenum Quad::drawMode()
{
    return GL_TRIANGLE_STRIP;
}

