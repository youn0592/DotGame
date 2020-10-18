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
    float m_posX = 0;
    float m_posY = 0;

    fw::ShaderProgram* m_pShader = nullptr;
    fw::ImGuiManager* m_pImGuiManager = nullptr;


    //Player* m_pPlayer = nullptr;

    fw::Mesh* m_pMeshHuman = nullptr;
    fw::Mesh* m_pMeshAnimal = nullptr;

    std::vector<fw::GameObject*> m_pObjects;

    fw::EventManager* m_pEventManager = nullptr;

    PlayerController* m_pPlayerController = nullptr;

    //Settings

    bool m_VSyncEnabled = true;
};