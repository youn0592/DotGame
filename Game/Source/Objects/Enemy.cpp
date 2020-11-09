#include "GamePCH.h"

#include "Enemy.h"

Enemy::Enemy(std::string name,int type, vec2 pos, vec2 playerPos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color) :
    fw::GameObject(name, pos, pMesh, pShader, pGameCore, color)
{
    m_ObjectName = name;

    m_EnemyType = type;

    m_PlayerPos = playerPos;
    m_Speed = float(rand() % 5 + 3 );

    m_Dir = m_PlayerPos - m_Position;
    m_Dir.normalize();

    m_SineZero = pos;

    if (m_EnemyType == 1) {
        m_Speed /= 1.5;
    }
}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{


    if (m_EnemyType == 0) {
        m_Position += m_Dir * m_Speed * deltaTime;
    }

    if (m_EnemyType == 1) {
        
        m_Speed += deltaTime * 20;

        m_Position += m_Dir * m_Speed * deltaTime;
    }
    if (m_EnemyType == 2) {
        
        m_SineZero += m_Dir * m_Speed * deltaTime;
        m_SineAnim += deltaTime * m_SineFreq;

        m_Position = m_SineZero + vec2(-m_Dir.y, m_Dir.x) * m_SineAmp * sinf(m_SineAnim);
    }

}


