#pragma once

namespace fw {

class Mesh
{
public:
    Mesh(int type);
    virtual ~Mesh();

    void Draw(float x, float y, ShaderProgram* pShader);

    void MakeAnimal();
    void MakeHuman();

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
};

} // namespace fw
