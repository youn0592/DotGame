#include "Framework.h"
#include "Game.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{

}

Game::~Game()
{
    if (m_pShader != nullptr) {
        delete m_pShader;
    }
    for (int i = 0; i < m_pGameObjects.size(); i++)
    {
        delete m_pGameObjects.at(i);
    }

}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/basic.vert","Data/basic.frag");
    fw::GameObject* m_pHuman = new fw::GameObject(0);
    fw::GameObject* m_pAnimal = new fw::GameObject(1);
    m_pImGuiManager = new fw::ImGuiManager(m_pFrameWork);

    m_pImGuiManager->Init();

    m_pGameObjects.push_back(m_pHuman);
    m_pGameObjects.push_back(m_pAnimal);

}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();
}

void Game::Draw()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4);

    glPointSize(10);

    for(int i = 0; i < m_pGameObjects.size(); i++)
    {
        m_pGameObjects.at(i)->Draw(m_posX, m_posY, m_pShader);
    }

    m_pImGuiManager->EndFrame();

}
