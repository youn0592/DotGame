#include "GamePCH.h"
#include "PlayerController.h"

PlayerController::PlayerController()
{
    
}

PlayerController::~PlayerController()
{

}

void PlayerController::Update(fw::GameCore* pGameCore)
{

    m_Up = false;
    m_Down = false;
    m_Right = false;
    m_Left = false;

    if (pGameCore->GetFramework()->IsKeyDown('W'))
    {
        m_Up = true;
    }
    if (pGameCore->GetFramework()->IsKeyDown('S'))
    {
        m_Down = true;
    }
    if (pGameCore->GetFramework()->IsKeyDown('A'))
    {
        m_Left = true;
    }
    if (pGameCore->GetFramework()->IsKeyDown('D'))
    {
        m_Right = true;
    }
}

bool PlayerController::IsUpHeld()
{
    return m_Up;
}

bool PlayerController::IsDownHeld()
{
    return m_Down;
}

bool PlayerController::IsRightHeld()
{
    return m_Right;
}

bool PlayerController::IsLeftHeld()
{
    return m_Left;
}
