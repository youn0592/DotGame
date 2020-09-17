#pragma once

namespace fw {

class Mesh
{
public:
    Mesh();
    virtual ~Mesh();

    void Draw();

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
};

} // namespace fw
