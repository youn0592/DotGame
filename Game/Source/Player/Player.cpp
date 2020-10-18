#include "GamePCH.h"

#include "Player/Player.h"
#include "Player/PlayerController.h"

Player::Player(std::string name, vec2 pos, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore)
    : fw::GameObject(name, pos, pMesh, pShader, pGameCore),
     m_pPlayerController(pPlayerController)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 2.0f;

    vec2 dir;

    if (m_pPlayerController->IsLeftHeld())
    {
        dir.x = -1;
    }
    if (m_pPlayerController->IsRightHeld())
    {
        dir.x = 1;
    }
    if (m_pPlayerController->IsUpHeld())
    {
        dir.y = 1;
    }
    if (m_pPlayerController->IsDownHeld())
    {
        dir.y = -1;
    }

    m_Position += dir * speed * deltaTime;
}
