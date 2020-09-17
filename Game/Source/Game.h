#pragma once

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game() override;

    void Init();
    virtual void Update() override;
    virtual void Draw() override;



protected:
    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pMesh = nullptr;
};