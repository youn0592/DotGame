#include "GamePCH.h"
#include "Shapes.h"

const float createHuman[] =
{
    0.6f, 0.5f,   //HeadTop - top
    0.5f, 0.4f,   //HeadTop - right
    0.7f, 0.4f,   //HeadTop - left
    0.6f, 0.3f,   //HeadBottom - bottom
    0.5f, 0.4f,   //HeadBottom - right
    0.7f, 0.4f,   //HeadBottom - left
    0.6f, 0.3f,   //Body - top
    0.8f, -0.2f,  //Body - left
    0.4f, -0.2f,  //Body - right
    0.8f, -0.2f,  //Left leg - left
    0.64f, -0.2f, //Left leg - right
    0.7f, -0.4f,  //Left leg - bottom
    0.55f, -0.2f, //Right leg - right
    0.4f, -0.2f,  //Right leg - left
    0.5f, -0.4f,  //Right leg - bottom

};

const int meshPrimTime_Human = GL_TRIANGLES;
const int meshNumVerts_Human = sizeof (createHuman) / (sizeof(float) * 2);

const float createAnimal[] =
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

const int meshPrimType_Animal = GL_LINES;
const int meshNumVerts_Animal = sizeof(createAnimal) / (sizeof(float) * 2);