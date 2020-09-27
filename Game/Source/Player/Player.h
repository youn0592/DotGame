#pragma once


class Player : public fw::GameObject
{
public:
    Player(float x, float y, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore);
    ~Player();

    void Update(float deltaTime);

protected:

    vec2 m_GameObjectVector = vec2(m_posX, m_posY);

private:
    const int SPEED = 4;
};