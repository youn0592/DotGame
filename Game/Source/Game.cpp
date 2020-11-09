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

    if (m_EnemyGreen != nullptr) {
        delete m_EnemyGreen;
    }

    if (m_EnemyWhite != nullptr)
    {
       delete m_EnemyWhite;
    }
    if (m_EnemyYellow != nullptr) {
        delete m_EnemyYellow;
    }

    delete m_pEventManager;

    delete m_pPlayerController;

    delete m_pImGuiManager;
}

void Game::Init()
{
    //OpenGL Settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    //Enemy Mesh's
    {
        m_EnemyGreen = new fw::Mesh();
        m_EnemyGreen->CreateCircle(0.3, 4, true);
        m_EnemyWhite = new fw::Mesh();
        m_EnemyWhite->CreateCircle(0.3, 6, true);
        m_EnemyYellow = new fw::Mesh();
        m_EnemyYellow->CreateCircle(0.3, 5, true);
    }

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

            int RandNum = rand() % m_enemySpawns;

            const float PI = 3.1415926f;
            float spawnAngle = float(rand() % 360);
            spawnAngle *= PI / 180;

            vec2 enemyPos = m_Mid + vec2(cosf(spawnAngle), (sinf(spawnAngle))) * m_ArenaRad;
            if (RandNum == 0) {
                m_pObjects.push_back(new Enemy("Enemy", RandNum, enemyPos, m_playerPosition, m_EnemyGreen, m_pShader, this, fw::vec4::Green()));
            }
            else if (RandNum == 1) {
                m_pObjects.push_back(new Enemy("Enemy", RandNum, enemyPos, m_playerPosition, m_EnemyYellow, m_pShader, this, fw::vec4::Yellow()));
            }
            else if (RandNum == 2) {
                m_pObjects.push_back(new Enemy("Enemy", RandNum, enemyPos, m_playerPosition, m_EnemyWhite, m_pShader, this, fw::vec4::White()));
            }
        }

        if (pEvent->GetType() == GameOverFromEvent::GetStaticEventType())
        {
            m_HasLost = true;
        }
        if(pEvent->GetType() == GameWinFromEvent::GetStaticEventType())
        {
            m_HasWon = true;
        }
        if (pEvent->GetType() == ResetFromEvent::GetStaticEventType())
        {
            for (auto it = m_pObjects.begin() + 1; it != m_pObjects.end(); it++) {
                fw::GameObject* pObject = *it;
                if (pObject->GetName() != "Circle") {
                    m_pEventManager->AddEvent(new RemoveFromGameEvent(pObject));
                }
            }
            if (m_LevelActive == true) {
                m_Level = 1;
                m_ArenaRad = 5.0f;
                m_Arena->CreateCircle(m_ArenaRad, 100, false);
                m_enemySpawns = 1;
            }


            m_pPlayer->SetPosition(m_Mid);

            m_LevelTimer = 0;
            m_HasWon = false;
            m_HasLost = false;
            m_SurvivalTimer = 0;
        }
        if (pEvent->GetType() == LevelWinFromEvent::GetStaticEventType())
        {
            m_Transition = true;
        }
        if (pEvent->GetType() == MenuFromEvent::GetStaticEventType()) {
            m_MenuActive = true;
        }
    }

void Game::Update(float deltaTime)
{

    //ImGui::ShowDemoWindow();

    if (m_pPlayerController->WasNewlyPressed(PlayerController::Mask::Reset)) {
        m_pEventManager->AddEvent(new ResetFromEvent());
    }
    else if (m_pPlayerController->WasNewlyPressed(PlayerController::Mask::Menu)) {
        m_pEventManager->AddEvent(new ResetFromEvent());
        m_pEventManager->AddEvent(new MenuFromEvent());
    }
    m_playerPosition = m_pPlayer->GetPosition();

    //Run Timer
    if(m_MenuActive == false){
        if (m_HasLost == false && m_HasWon == false) {
            if (m_Transition == false) {
                m_Timer += deltaTime;
                if (m_Timer >= m_TimerSpawn)
                {
                    m_pEventManager->AddEvent(new AddFromGameEvent());

                    m_Timer = 0;
                }
            }

            if (m_LevelActive == true) {
                m_LevelTimer += deltaTime;
                if (m_LevelTimer >= 5.0f)
                {
                    m_Transition = true;
                }

                if (m_LevelTimer >= 7.0f)
                {
                    m_Transition = false;
                    m_LevelTimer = 0.0f;
                    m_Level++;
                    if (m_enemySpawns != 3) {
                        m_enemySpawns++;
                    }
                }
                if (m_Level == 6) {
                    m_pEventManager->AddEvent(new GameWinFromEvent());
                }
            }
            else {
                m_SurvivalTimer += deltaTime;
            }
        }
    }

    //Circle Debug List
        GameText();
    

    //Circle staying in the Arena
    if((m_pPlayer->GetPosition() - m_Mid).magnitude() >= m_ArenaRad - m_Rads )
    {
        vec2 collide = (m_pPlayer->GetPosition() - m_Mid).normalize();
        collide *=  m_ArenaRad - m_Rads;

        m_pPlayer->SetPosition(collide + m_Mid);
    }


    //Updating Characters and Collision
    if (m_MenuActive == false) {
        if (m_Transition == false) {
            for (auto it = m_pObjects.begin(); it != m_pObjects.end(); it++)
            {
                fw::GameObject* pObject = *it;

                pObject->Update(deltaTime);

                if (pObject->GetName() == "Enemy")
                {
                    if ((pObject->GetPosition() - m_Mid).magnitude() >= m_ArenaRad) {

                        m_pEventManager->AddEvent(new RemoveFromGameEvent(pObject));

                    }

                    //Collision
                    {
                        float disSqrd = sqrt((pObject->GetPosition().x - m_pPlayer->GetPosition().x) * (pObject->GetPosition().x - m_pPlayer->GetPosition().x) + (pObject->GetPosition().y - m_pPlayer->GetPosition().y) * (pObject->GetPosition().y - m_pPlayer->GetPosition().y));
                        float RadiiSqrd = (pObject->GetRadius() + m_pPlayer->GetRadius()) * (pObject->GetRadius() + m_pPlayer->GetRadius());
                        bool IsCollide = disSqrd <= RadiiSqrd;

                        if (IsCollide == true)
                        {
                            m_pEventManager->AddEvent(new GameOverFromEvent());
                        }
                    }
                }



            }
        }
    }

    if (m_Transition == true) {
        m_ArenaRad -= 0.005;
        m_Arena->CreateCircle(m_ArenaRad, 100, false);
    }

    ////ImGUI debug stuff
    //{
    //    if (ImGui::Checkbox("VSync", &m_VSyncEnabled)) {
    //        wglSwapInterval(m_VSyncEnabled ? 1 : 0);
    //    }
    //}
}

void Game::Draw()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);

    if (m_HasLost == false) {
        m_pPlayer->Draw();
    }

    for (auto it = m_pObjects.begin() + 1; it != m_pObjects.end(); it++)
    {
        fw::GameObject* pObject = *it;

        pObject->Draw();
    }

    m_pImGuiManager->EndFrame();

}

void Game::GameText()
{

    if (m_MenuActive == true) {
        ImGui::Begin("Main Menu");
        ImGui::Text("Welcome!");
        if (ImGui::Button("Level Mode")) {
            m_LevelActive = true;
            m_MenuActive = false;
            m_enemySpawns = 1;
        }
        if (ImGui::Button("Survival Mode")) {
            m_LevelActive = false;
            m_enemySpawns = 3;
            m_MenuActive = false;
        }
        ImGui::End();
    }
    else {
        if (m_LevelActive == true) {
            ImGui::Begin("Levels Rules & Stats");
            ImGui::Text("Beat 5 levels to win");
            ImGui::Text("Survive for 5 seconds to win level");
            ImGui::Text("Arena will shrink every level");
            ImGui::Text("Current Level: %i", (m_Level));
            ImGui::Text("Current Time: %.1f", (m_LevelTimer));
            ImGui::End();
        }
        else {
            ImGui::Begin("Survival Rules & Stats");
            ImGui::Text("Survive as long as possible");
            ImGui::Text("All Enemies are active");
            ImGui::Text("Time Survived: %.2f", (m_SurvivalTimer));
            ImGui::End();
        }
    }

    if (m_HasLost == true) {
        ImGui::Begin("You Lose!");
        ImGui::Text("Game Over");
        ImGui::Text("Press 'R' to reset and try again");
        ImGui::Text("Press 'M' to go back to the menu");
        if (m_LevelActive != true) {
            ImGui::Text("You Survived: %.1f seconds", (m_SurvivalTimer));
        }
        else {
            ImGui::Text("You made it to level %i", (m_Level));
        }
        ImGui::End();
    }
    else if (m_HasWon == true) {
        ImGui::Begin("You Win!");
        ImGui::Text("You Win!");
        ImGui::Text("Press 'R' to reset and try again");
        ImGui::Text("Press 'M' to go back to the menu");
        ImGui::End();
    }
    else if (m_Transition == true) {
        ImGui::Begin("Level Win");
        ImGui::Text("You beat Level: %i", (m_Level));
        ImGui::End();
    }
    
    //Debug Menu
    {
        //if (ImGui::SliderInt("Player Sides", &m_verts, 3, 100))
//{
//    m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
//}

//if (ImGui::SliderFloat("Player Radius", &m_Rads, 0.1f, 3.0f))
//{
//    m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
//}

//if (ImGui::Checkbox("Player Is Filled", &m_isFilled)) {

//    m_Character->CreateCircle(m_Rads, m_verts, m_isFilled);
//}
        //if (ImGui::SliderFloat("Spawn Timer", &m_TimerSpawn, 0.0f, 5.0f))
        //{

        //}
    }
}







