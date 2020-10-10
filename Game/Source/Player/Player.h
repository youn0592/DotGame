#pragma once

class Player : public fw::GameObject
{
public:
    Player(std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:
};
