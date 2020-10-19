#pragma once

class PlayerController;

class Player : public fw::GameObject
{
public:
    Player(std::string name, vec2 pos, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:

    PlayerController* m_pPlayerController = nullptr;
};
