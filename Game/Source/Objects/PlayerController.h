#pragma once

class PlayerController
{
public:

    enum
    {
        Up = 1,
        Down = 2,
        Left = 4,
        Right = 8,
        Boost = 16
    };
    

    PlayerController();
    virtual ~PlayerController();

    void OnEvent(fw::Event* pEvent);

    bool IsUpHeld() { return (m_Flags & Up) != 0; }
    bool IsDownHeld() { return (m_Flags & Down) != 0; }
    bool IsLeftHeld() { return (m_Flags & Left) != 0; }
    bool IsRightHeld() { return (m_Flags & Right) != 0; }
    bool IsBoostHeld() { return (m_Flags & Boost) != 0; }


protected:

    unsigned int m_Flags = 0;

    //bool m_Up = false;
    //bool m_Down = false;
    //bool m_Left = false;
    //bool m_Right = false;
    //bool m_Boost = false;
};
