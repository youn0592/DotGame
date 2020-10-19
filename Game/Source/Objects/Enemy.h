#pragma once

class Enemy : public fw::GameObject
{
public:
    Enemy(std::string name, vec2 pos, vec2 playerPos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color);
    virtual ~Enemy();

    virtual void Update(float deltaTime) override;

protected: 
     
    vec2 m_PlayerPos;

    vec2 m_Dir;
    float m_Speed;
};