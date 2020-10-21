#pragma once

namespace fw {

    class Event;
    class EventManager;
    class FWCore;

    class GameCore
    {
    public:
        GameCore(FWCore* pFramework);
        virtual ~GameCore();

        virtual void StartFrame(float deltaTime) = 0;
        virtual void OnEvent(fw::Event* pEvent) = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;

        fw::FWCore* GetFramework();
        EventManager* GetEventManager() { return m_pEventManager; }


    protected:
        FWCore* m_pFrameWork = nullptr;

        EventManager* m_pEventManager = nullptr;
    };

} //Namespace fw

