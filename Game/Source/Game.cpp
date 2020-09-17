#include "Framework.h"
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
    if (m_pShader != nullptr) {
        delete m_pShader;
    }
    if (m_pMesh != nullptr) {
        delete m_pMesh;
    }
}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/basic.vert","Data/basic.frag");
    m_pMesh = new fw::Mesh();
}

void Game::Update()
{
}

void Game::Draw()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    m_pMesh->Draw();
}
