#include "Framework.h"
#include "GameObject.h"

namespace fw {
    GameObject::GameObject(float x, float y, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore)
    {
        m_pMesh = pMesh;
        m_pShader = pShader;
        m_posX = x;
        m_posY = y;
        m_pGameCore = pGameCore;
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Update()
    {
    }

    void GameObject::Draw()
    {
      m_pMesh->Draw(m_posX, m_posY, m_pShader);
    }

    void GameObject::GetFrameWork()
    {
        m_pGameCore->GetFramework();
    }
}
