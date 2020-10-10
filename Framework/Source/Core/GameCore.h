#pragma once

namespace fw {

    class Event;
    class FWCore;

    class GameCore
    {
    public:
        GameCore(FWCore* pFramework);
        virtual ~GameCore();

        virtual void OnEvent(fw::Event* pEvent) = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;

        fw::FWCore* GetFramework();


    protected:
        FWCore* m_pFrameWork = nullptr;
    };

} //Namespace fw

