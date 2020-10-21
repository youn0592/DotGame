#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Objects/PlayerController.h"
#include "Objects/Enemy.h"
#include "Events/GameEvents.h"



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

    if (m_Arena != nullptr) {
        delete m_Arena;
    }

    if (m_Character != nullptr) {
        delete m_Character;
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

    m_pImGuiManager = new fw::ImGuiManager(m_pFrameWork);
    m_pImGuiManager->Init();

    m_pShader = new fw::ShaderProgram("Data/basic.vert","Data/basic.frag");

    m_pEventManager = new fw::EventManager();
    m_pPlayerController = new PlayerController();

    CreateMesh();

}

void Game::CreateMesh()
{


    m_Arena = new fw::Mesh();
    m_Character = new fw::Mesh();

    m_Arena->CreateCircle(m_ArenaRad, 100, false);
    m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);

    m_Enemy = new fw::Mesh();
    m_Enemy->CreateCircle(0.3, 4, true);
   
    m_pPlayer = new Player("Character", m_Mid, m_pPlayerController, m_Character, m_pShader, this, fw::vec4::Blue());
    m_pObjects.push_back(m_pPlayer);
    m_pObjects.push_back(new fw::GameObject("Circle", m_Mid, m_Arena, m_pShader, this, fw::vec4::Red()));
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);

    m_pPlayerController->StartFrame();

    m_pEventManager->DispatchAllEvents(this);
}

void Game::OnEvent(fw::Event* pEvent)
{
        m_pPlayerController->OnEvent(pEvent);

        if (pEvent->GetType() == RemoveFromGameEvent::GetStaticEventType())
        {
            RemoveFromGameEvent* pRemoveFromGameEvent = static_cast<RemoveFromGameEvent*>(pEvent);
            fw::GameObject* pObject = pRemoveFromGameEvent->GetGameObject();

            auto it = std::find(m_pObjects.begin(), m_pObjects.end(), pObject);
            m_pObjects.erase(it);

            delete pObject;
        }

        if (pEvent->GetType() == AddFromGameEvent::GetStaticEventType())
        {
            AddFromGameEvent* pAddFromGameEvent = static_cast<AddFromGameEvent*>(pEvent);

            const float PI = 3.1415926f;
            float spawnAngle = float(rand() % 360);
            spawnAngle *= PI / 180;

            vec2 enemyPos = m_Mid + vec2(cosf(spawnAngle), (sinf(spawnAngle))) * m_ArenaRad;

            m_pObjects.push_back(new Enemy("Enemy", enemyPos, m_playerPosition, m_Enemy, m_pShader, this, fw::vec4::Green()));
        }
    }

void Game::Update(float deltaTime)
{

    //ImGui::ShowDemoWindow();

    m_playerPosition = m_pPlayer->GetPosition();

    //Run Timer
    m_Timer += deltaTime;
    if (m_Timer >= m_TimerSpawn) 
    {
        m_pEventManager->AddEvent(new AddFromGameEvent());

        m_Timer = 0;
    }

    //Circle Debug List
    {
        if (ImGui::SliderInt("Player Sides", &m_verts, 3, 100))
        {
            m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
        }

        if (ImGui::SliderFloat("Player Radius", &m_Rads, 0.1f, 3.0f))
        {
            m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
        }

        if (ImGui::Checkbox("Player Is Filled", &m_isFilled)) {

            m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
        }
        if (ImGui::SliderFloat("Spawn Timer", &m_TimerSpawn, 0.0f, 5.0f)) 
        {

        }
    }

    if((m_pPlayer->GetPosition() - m_Mid).magnitude() >= m_ArenaRad - m_Rads )
    {
        vec2 collide = (m_pPlayer->GetPosition() - m_Mid).normalize();
        collide *=  m_ArenaRad - m_Rads;

        m_pPlayer->SetPosition(collide + m_Mid);
    }

    for (auto it = m_pObjects.begin(); it != m_pObjects.end(); it++)
    {
        fw::GameObject* pObject = *it;

        pObject->Update(deltaTime);

        if (pObject->GetName() != "Character")
        {
            if ((pObject->GetPosition() - m_Mid).magnitude() >= m_ArenaRad) {

                m_pEventManager->AddEvent(new RemoveFromGameEvent(pObject));

            }
        }
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
