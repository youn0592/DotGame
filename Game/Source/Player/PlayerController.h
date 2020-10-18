#pragma once

class PlayerController {

public:
    PlayerController();
    virtual ~PlayerController();

    void Update(fw::GameCore* pGameCore);

    bool IsUpHeld();
    bool IsDownHeld();
    bool IsRightHeld();
    bool IsLeftHeld();

protected:

    bool m_Up = false;
    bool m_Down = false;
    bool m_Right = false;
    bool m_Left = false;

};