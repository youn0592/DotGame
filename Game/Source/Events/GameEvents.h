#pragma once

class RemoveFromGameEvents : public fw::Event {
public:
    RemoveFromGameEvents(fw::GameObject* pObject)
    {
        m_pGameObject = pObject;
    }

    static const char* GetStaticEventType() 
    {
        return "RemoveFromGameEvent";
    }
    virtual const char* GetType() override
    {
        return "RemoveFromGameEvent";
    }

    virtual ~RemoveFromGameEvents() {}

    fw::GameObject* GetGameObject() { return m_pGameObject; }

protected:
    fw::GameObject* m_pGameObject;
};