#pragma once
namespace fw {
    class GameObject
    {
    public:
        GameObject(int type);
        ~GameObject();

        void Update();
        void Draw(float x, float y, fw::ShaderProgram* pShader);

    protected:
        float m_positionX = 0;
        float m_positionY = 0;

        fw::Mesh* m_pMesh = nullptr;
        fw::ShaderProgram* m_pShader = nullptr;
    };
}