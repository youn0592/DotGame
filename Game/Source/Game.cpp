#include "Framework.h"
#include "Game.h"
#include "Player/Player.h"

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

    if(m_pMeshAnimal != nullptr)
    {
        delete m_pMeshAnimal;
    }

    if (m_pMeshHuman != nullptr)
    {
        delete m_pMeshHuman;
    }

    if(m_pPlayer != nullptr)
    {
        delete m_pPlayer;
    }
}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/basic.vert","Data/basic.frag");

    CreateMesh();

}

void Game::CreateMesh()
{
    // Define our triangle as 3 positions.
    float createHuman[] =
    {
        0.6f, 0.5f,   //HeadTop - top
        0.5f, 0.4f,   //HeadTop - right
        0.7f, 0.4f,   //HeadTop - left
        0.6f, 0.3f,   //HeadBottom - bottom
        0.5f, 0.4f,   //HeadBottom - right
        0.7f, 0.4f,   //HeadBottom - left
        0.6f, 0.3f,   //Body - top
        0.8f, -0.2f,  //Body - left
        0.4f, -0.2f,  //Body - right
        0.8f, -0.2f,  //Left leg - left
        0.64f, -0.2f, //Left leg - right
        0.7f, -0.4f,  //Left leg - bottom
        0.55f, -0.2f, //Right leg - right
        0.4f, -0.2f,  //Right leg - left
        0.5f, -0.4f,  //Right leg - bottom

    };
    m_pMeshHuman = new fw::Mesh(15, GL_TRIANGLES, createHuman);

    float createAnimal[] =
    {
        0.2f, 0.6f, //Head - Left
        0.3f, 0.6f,  //Head - Right
        0.3f, 0.6f, //Neck - Top
        0.4f, 0.5f, //Neck - Bottom
        0.4f, 0.5f, //Body - Left
        0.6f, 0.5f, //Body Right
        0.6f, 0.5f, //Back Leg - Back
        0.7f, 0.3f, //Back Leg - Front
        0.4f, 0.5f, //Front Leg - Back
        0.4f, 0.3f, //Front Leg - Front

    };
    m_pMeshAnimal = new fw::Mesh(10, GL_LINES, createAnimal);

    m_pImGuiManager = new fw::ImGuiManager(m_pFrameWork);

    m_pImGuiManager->Init();

    fw::GameObject* m_pAnimal = new fw::GameObject(5, 5, m_pMeshAnimal, m_pShader, this);

    m_pPlayer = new Player(4, 5, m_pMeshHuman, m_pShader, this);

     m_pGameObjects.push_back(m_pAnimal);
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

    m_pPlayer->Update(deltaTime);
}

void Game::Draw()
{
    glClearColor(0, 0.5, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4);

    glPointSize(10);

    for (int i = 0; i < m_pGameObjects.size(); i++)
    {
        m_pGameObjects.at(i)->Draw();
    }

    m_pPlayer->Draw();

    m_pImGuiManager->EndFrame();

}
