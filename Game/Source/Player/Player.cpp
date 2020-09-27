#include "Framework.h"
#include "Player.h"

Player::Player(float x, float y, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore) : fw::GameObject(x, y, pMesh, pShader, pGameCore)
{
}

Player::~Player()
{
}


void Player::Update(float deltaTime)
{

    if(m_pGameCore->GetFramework()->IsKeyDown('W') == true)
    {
        m_posY += SPEED * deltaTime;
    }

    if (m_pGameCore->GetFramework()->IsKeyDown('A') == true)
    {
        m_posX -= SPEED * deltaTime;
    }

    if (m_pGameCore->GetFramework()->IsKeyDown('S') == true)
    {
        m_posY -= SPEED * deltaTime;
    }

    if (m_pGameCore->GetFramework()->IsKeyDown('D') == true)
    {
        m_posX += SPEED * deltaTime;
    }
}
