#include "FrameworkPCH.h"
#include "Utility/ShaderProgram.h"

#include "Mesh.h"

namespace fw {

Mesh::Mesh(int type)
{
    if(type == 0)
    {
        MakeAnimal();
    }
    else
    {
        MakeHuman();
    }
}

Mesh::~Mesh()
{

}

void Mesh::Draw(float x, float y, ShaderProgram* pShader)
{
    glUseProgram(pShader->GetProgram());

    // Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    // Get the attribute variable’s location from the shader.
    GLint loc = 0; //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray( loc );

    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

    // Draw the primitive.
    glDrawArrays( m_PrimitiveType, 0, m_NumVertices );
}

void Mesh::CreateShape(int numVertices, int primitiveType, float* pVertices)
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

void Mesh::MakeAnimal()
{
    // Generate a buffer for our vertex attributes.
    glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    // Define our triangle as 3 positions.
    float attribs[] =
    {
        0.2f, 0.6f, //Head - Left
        0.3f, 0.6f,  //Head - Right
        0.3f, 0.6f, //Neck - Top
        0.4f, 0.5f, //Neck - Bottom
        0.4f, 0.5f, //Body - Left
        0.6f, 0.5f, //Body Right
        0.6f, 0.5f, //Back Leg - Back
        0.7f, 0.3f, //Back Leg - Front
        0.4f, 0.5f, //Front Leg - Back
        0.4f, 0.3f, //Front Leg - Front

    };

    m_NumVertices = 10;
    m_PrimitiveType = GL_LINES;

    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, attribs, GL_STATIC_DRAW);
}

void Mesh::MakeHuman()
{
    // Generate a buffer for our vertex attributes.
    glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    // Define our triangle as 3 positions.
    float attribs[] =
    {
        -0.6f, 0.5f,   //HeadTop - top
        -0.5f, 0.4f,   //HeadTop - right
        -0.7f, 0.4f,   //HeadTop - left
        -0.6f, 0.3f,   //HeadBottom - bottom
        -0.5f, 0.4f,   //HeadBottom - right
        -0.7f, 0.4f,   //HeadBottom - left
        -0.6f, 0.3f,   //Body - top
        -0.8f, -0.2f,  //Body - left
        -0.4f, -0.2f,  //Body - right
        -0.8f, -0.2f,  //Left leg - left
        -0.64f, -0.2f, //Left leg - right
        -0.7f, -0.4f,  //Left leg - bottom
        -0.55f, -0.2f, //Right leg - right
        -0.4f, -0.2f,  //Right leg - left
        -0.5f, -0.4f,  //Right leg - bottom

    };

    m_NumVertices = 15;
    m_PrimitiveType = GL_TRIANGLES;

    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, attribs, GL_STATIC_DRAW);
}
} // namespace fw
