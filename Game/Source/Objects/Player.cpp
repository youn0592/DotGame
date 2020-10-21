#include "GamePCH.h"

#include "Objects/Player.h"
#include "Objects/PlayerController.h"

Player::Player(std::string name, vec2 pos, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color)
    : fw::GameObject(name, pos, pMesh, pShader, pGameCore, color),
     m_pPlayerController(pPlayerController)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 4.0f;

    vec2 dir;

    if (m_pPlayerController->IsHeld(PlayerController::Mask::Left))
    {
        dir.x += -1;
    }
    if (m_pPlayerController->IsHeld(PlayerController::Mask::Right))
    {
        dir.x += 1;
    }
    if (m_pPlayerController->IsHeld(PlayerController::Mask::Up))
    {
        dir.y += 1;
    }
    if (m_pPlayerController->IsHeld(PlayerController::Mask::Down))
    {
        dir.y += -1;
    }
    if (m_pPlayerController->IsHeld(PlayerController::Mask::Boost)) 
    {
        speed *= 2;
    }

    dir.normalize();

    m_Position += dir * speed * deltaTime;
}
