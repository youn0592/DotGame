#pragma once

#include "Math/Vector.h"

namespace fw {

    class GameCore;
    class Mesh;
    class ShaderProgram;

    class GameObject
    {
    public:
        GameObject(std::string name, vec2 pos, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore);
        virtual ~GameObject();

        virtual void Update(float deltaTime);
        virtual void Draw();

        void GetFrameWork();

        std::string GetName();

    protected:

        vec2 m_Position;

        Mesh* m_pMesh = nullptr;
        ShaderProgram* m_pShader = nullptr;
        GameCore* m_pGameCore = nullptr;

        std::string m_Name;
    };
}