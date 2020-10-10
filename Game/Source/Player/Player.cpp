#include "GamePCH.h"

#include "Player/Player.h"

Player::Player(std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore)
    : fw::GameObject(name, pos, pMesh, pShader, pGameCore)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 2.0f;

    vec2 dir;

    if (m_pGameCore->GetFramework()->IsKeyDown('A'))
    {
        dir.x = -1;
    }
    if (m_pGameCore->GetFramework()->IsKeyDown('D'))
    {
        dir.x = 1;
    }
    if (m_pGameCore->GetFramework()->IsKeyDown('W'))
    {
        dir.y = 1;
    }
    if (m_pGameCore->GetFramework()->IsKeyDown('S'))
    {
        dir.y = -1;
    }

    m_Position += dir * speed * deltaTime;
}
