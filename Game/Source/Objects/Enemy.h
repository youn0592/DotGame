#pragma once

class Enemy : public fw::GameObject
{
public:
    Enemy(std::string name, int type, vec2 pos, vec2 playerPos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore, fw::vec4 color);
    virtual ~Enemy();

    virtual void Update(float deltaTime) override;


protected: 
     
    vec2 m_PlayerPos;

    int m_EnemyType;

    vec2 m_Dir;
    float m_Speed;

    float m_PI = 3.1415926f;

    vec2 m_SineZero;
    float m_SineAmp = 0.75;
    float m_SineFreq = 5;
    float m_SineAnim = 0;

    float m_Timer = 0;

    std::string m_ObjectName;
};