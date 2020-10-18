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

    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;



protected:

    //Circle Members
    int m_verts = 15;
    float m_Rads = 0.3f;
    fw::vec2 m_Mid = vec2(5, 5);
    bool m_isFilled = true;

    //Shaders / ImGui
    fw::ShaderProgram* m_pShader = nullptr;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    //Meshes
    fw::Mesh* m_Arena = nullptr;
    fw::Mesh* m_Character = nullptr;
    std::vector<fw::GameObject*> m_pObjects;
    PlayerController* m_pPlayerController = nullptr;

    //Settings

    bool m_VSyncEnabled = true;
};