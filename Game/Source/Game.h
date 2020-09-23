#pragma once

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game() override;

    void Init();
    virtual void Update() override;
    virtual void Draw() override;



protected:
    float m_posX = 0;
    float m_posY = 0;

    fw::ShaderProgram* m_pShader = nullptr;

    std::vector<fw::GameObject*> m_pGameObjects;
};