#include "GamePCH.h"

#include "Enemy.h"

Enemy::Enemy(std::string name, vec2 pos, vec2 playerPos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color) :
    fw::GameObject(name, pos, pMesh, pShader, pGameCore, color)
{
    m_PlayerPos = playerPos;
    m_Speed = float(rand() % 7 + 3 );

    m_Dir = m_PlayerPos - m_Position;
    m_Dir.normalize();


}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{

    m_Position += m_Dir * m_Speed * deltaTime;
}

