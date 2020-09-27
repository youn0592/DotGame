#pragma once
namespace fw {

    class GameCore;
    class Mesh;
    class ShaderProgram;

    class GameObject
    {
    public:
        GameObject(float x, float y, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore);
        ~GameObject();

        void Update();
        void Draw();

        void GetFrameWork();

    protected:
        float m_posX = 0;
        float m_posY = 0;

        Mesh* m_pMesh = nullptr;
        ShaderProgram* m_pShader = nullptr;
        GameCore* m_pGameCore = nullptr;
    };
}