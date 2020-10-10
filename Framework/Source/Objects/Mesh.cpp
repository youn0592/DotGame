#include "FrameworkPCH.h"
#include "Framework.h"
#include "Utility/ShaderProgram.h"
#include "Utility/Helpers.h"

#include "Mesh.h"

namespace fw {


Mesh::Mesh(int numVertices, int primitiveType, const float* pVertices)
{
    CreateShape(numVertices, primitiveType, pVertices);
}

Mesh::~Mesh()
{

}

void Mesh::SetUniform1F(ShaderProgram* pShader, char* name, float value)
{
    //Setup our Uniforms
    {
        int loc = glGetUniformLocation(pShader->GetProgram(), name);
        glUniform1f(loc, value);
    }
}

void Mesh::SetUniform2F(ShaderProgram* pShader, char* name, float value1, float value2)
{
    int loc = glGetUniformLocation(pShader->GetProgram(), name);
    glUniform2f(loc, value1, value2);
}

void Mesh::SetUniform2F(ShaderProgram* pShader, char* name, vec2 values)
{
    int loc = glGetUniformLocation(pShader->GetProgram(), name);
    glUniform2f(loc, values.x, values.y);
}

void Mesh::Draw(vec2 pos, ShaderProgram* pShader)
{
    glUseProgram(pShader->GetProgram());

    // Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    // Get the attribute variable’s location from the shader.
    GLint loc = 0; //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray( loc );

    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

   {
        SetUniform1F(pShader, "u_Time", (float)GetSystemTimeSinceGameStart());
        SetUniform2F(pShader, "u_Pos", pos);
    }

    
    
    // Draw the primitive.
    glDrawArrays( m_PrimitiveType, 0, m_NumVertices );
}

void Mesh::CreateShape(int numVertices, int primitiveType, const float* pVertices)
{
    // Generate a buffer for our vertex attributes.
    glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    m_NumVertices = numVertices;
    m_PrimitiveType = primitiveType;

    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, pVertices, GL_STATIC_DRAW);
}


} // namespace fw
