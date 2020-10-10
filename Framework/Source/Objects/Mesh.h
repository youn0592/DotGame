#pragma once

#include "../Math/Vector.h"

namespace fw {


class Mesh
{
public:

    Mesh(int numVertices, int primitiveType, const float* pVertices);

    virtual ~Mesh();

    void SetUniform1F(ShaderProgram* pShader, char* name, float value);
    void SetUniform2F(ShaderProgram* pShader, char* name, float value1, float value2);
    void SetUniform2F(ShaderProgram* pShader, char* name, vec2 values);


    void Draw(vec2 pos, ShaderProgram* pShader);

    void CreateShape(int numVertices, int primitiveType, const float* pVertices);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
};

} // namespace fw
