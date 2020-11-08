#pragma once

#include "Math/Vector.h"

namespace fw {

    class GameCore;
    class Mesh;
    class ShaderProgram;

    class GameObject
    {
    public:
        GameObject(std::string name, vec2 pos, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore, vec4 color);
        virtual ~GameObject();

        virtual void Update(float deltaTime);
        virtual void Draw();

        void GetFrameWork();

        void SetPosition(vec2 pos);
        vec2 GetPosition();

        std::string GetName();

        float GetRadius();

        void SetColor(vec4 color);

    protected:

        vec2 m_Position;

        Mesh* m_pMesh = nullptr;
        ShaderProgram* m_pShader = nullptr;
        GameCore* m_pGameCore = nullptr;

        vec4 m_Color = vec4(1,1,1,1);

        std::string m_Name;
    };
}