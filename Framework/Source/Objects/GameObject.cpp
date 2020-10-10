#include "FrameworkPCH.h"
#include "Framework.h"
#include "GameObject.h"

namespace fw {
    GameObject::GameObject(std::string name, vec2 pos, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore)
    {
        m_pMesh = pMesh;
        m_pShader = pShader;
        m_Position = pos;
        m_pGameCore = pGameCore;
        m_Name = name;
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Update(float deltaTime)
    {
    }

    void GameObject::Draw()
    {
      m_pMesh->Draw(m_Position, m_pShader);
    }

    void GameObject::GetFrameWork()
    {
        m_pGameCore->GetFramework();
    }
    std::string GameObject::GetName()
    {
        return m_Name;
    }
}
