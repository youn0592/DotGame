#include "Framework.h"
#include "GameObject.h"

namespace fw {
    GameObject::GameObject(int type)
    {
        m_pMesh = new fw::Mesh(type);
    }

    GameObject::~GameObject()
    {
        if(m_pMesh != nullptr)
        {
            delete m_pMesh;
        }

        if(m_pShader != nullptr)
        {
            delete m_pShader;
        }
    }

    void GameObject::Update()
    {
    }

    void GameObject::Draw(float x, float y, fw::ShaderProgram* pShader)
    {
      m_pMesh->Draw(x, y, pShader);
    }
}
