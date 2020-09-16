#pragma once

class Game : public fw::GameCore
{
public:
    virtual ~Game() override;

    virtual void Update() override;
    virtual void Draw() override;
};