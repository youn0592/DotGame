#pragma once

namespace fw {

class Mesh
{
public:
    Mesh(int type);
    virtual ~Mesh();

    void SetUniform1F(ShaderProgram* pShader, char* name, float value);
    void Draw(float x, float y, ShaderProgram* pShader);

    void CreateShape(int numVertices, int primitiveType, float* pVertices);

    void MakeAnimal();
    void MakeHuman();

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
};

} // namespace fw
