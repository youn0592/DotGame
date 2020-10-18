#include "GamePCH.h"
#include "Game.h"
#include "Player/Player.h"
#include "Player/Shapes.h"
#include "Player/PlayerController.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
}

Game::~Game()
{
    if (m_pShader != nullptr) {
        delete m_pShader;
    }

    for (int i = 0; i < m_pObjects.size(); i++)
    {
        delete m_pObjects.at(i);
    }

    if(m_pMeshAnimal != nullptr)
    {
        delete m_pMeshAnimal;
    }

    if (m_pMeshHuman != nullptr)
    {
        delete m_pMeshHuman;
    }

  /*  if(m_pPlayer != nullptr)
    {
        delete m_pPlayer;
    }*/

    delete m_pEventManager;

    delete m_pPlayerController;
}

void Game::Init()
{
    wglSwapInterval(m_VSyncEnabled ? 1 : 0);

    m_pShader = new fw::ShaderProgram("Data/basic.vert","Data/basic.frag");

    m_pPlayerController = new PlayerController();

    CreateMesh();

}

void Game::CreateMesh()
{
    // Define our triangle as 3 positions.


    fw::Mesh* Circle = new fw::Mesh();
    Circle->CreateCircle(2.0f, 15, false);

    m_pObjects.push_back(new fw::GameObject("Circle", vec2(5,5), Circle, m_pShader, this));

    m_pImGuiManager = new fw::ImGuiManager(m_pFrameWork);
    m_pImGuiManager->Init();

    m_pEventManager = new fw::EventManager();

    // Create some GameObjects.
    //m_pObjects.push_back(new Player("Player", vec2(6, 5), m_pPlayerController, m_pMeshHuman, m_pShader, this));
    //m_pObjects.push_back(new fw::GameObject("Enemy 1", vec2(0, 0), m_pMeshAnimal, m_pShader, this));
    //m_pObjects.push_back(new fw::GameObject("Enemy 2", vec2(10, 10), m_pMeshAnimal, m_pShader, this));
    //m_pObjects.push_back(new fw::GameObject("Enemy 3", vec2(5, 5), m_pMeshAnimal, m_pShader, this));
    //m_pObjects.push_back(new fw::GameObject("Enemy 4", vec2(1, 1), m_pMeshAnimal, m_pShader, this));
    //m_pObjects.push_back(new fw::GameObject("Enemy 5", vec2(1, 9), m_pMeshAnimal, m_pShader, this));
}

void Game::OnEvent(fw::Event* pEvent)
{
}

void Game::Update(float deltaTime)
{
    // Process our events.
    m_pEventManager->DispatchAllEvents(this);

    m_pPlayerController->Update(this);

    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

    for (auto it = m_pObjects.begin(); it != m_pObjects.end(); it++)
    {
        fw::GameObject* pObject = *it;

        pObject->Update(deltaTime);

        //ImGui::PushID( pObject );
        //ImGui::Text( "Name: %s", pObject->GetName().c_str() );
        //ImGui::SameLine();
        //if( ImGui::Button( "Delete" ) )
        //{
        //    m_pEventManager->AddEvent( new RemoveFromGameEvent( pObject ) );
        //}
        //ImGui::PopID();
    }

    //ImGUI debug stuff
    {
        if (ImGui::Checkbox("VSync", &m_VSyncEnabled)) {
            wglSwapInterval(m_VSyncEnabled ? 1 : 0);
        }
    }
}

void Game::Draw()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);

    for (auto it = m_pObjects.begin(); it != m_pObjects.end(); it++)
    {
        fw::GameObject* pObject = *it;

        pObject->Draw();
    }

    m_pImGuiManager->EndFrame();

}
