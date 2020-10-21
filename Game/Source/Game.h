#pragma once

class Player;
class PlayerController;

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game() override;

    void Init();

    void CreateMesh();

    virtual void StartFrame(float deltaTime) override;

    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    Player* GetPlayer() { return m_pPlayer; }

protected:

    //Circle Members
    int m_verts = 15;
    float m_Rads = 0.3f;
    fw::vec2 m_Mid = vec2(5, 5);
    bool m_isFilled = true;

    //Arena Members
    float m_Timer = 0.0f;
    float m_TimerSpawn = 0.5f;
    float m_ArenaRad = 4.0f;;

    vec2 m_playerPosition;

    //Shaders / ImGui
    fw::ShaderProgram* m_pShader = nullptr;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    //Meshes
    fw::Mesh* m_Arena = nullptr;
    fw::Mesh* m_Character = nullptr;

    fw::Mesh* m_Enemy = nullptr;

    Player* m_pPlayer = nullptr;
    std::vector<fw::GameObject*> m_pObjects;
    PlayerController* m_pPlayerController = nullptr;

    //Settings

    bool m_VSyncEnabled = true;
};