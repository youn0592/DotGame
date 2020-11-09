#pragma once

class RemoveFromGameEvent : public fw::Event
{
public:
    RemoveFromGameEvent(fw::GameObject* pObject)
    {
        m_pObject = pObject;
    }
    virtual ~RemoveFromGameEvent() {}

    static const char* GetStaticEventType() { return "RemoveFromGameEvent"; }
    virtual const char* GetType() override { return GetStaticEventType(); }

    fw::GameObject* GetGameObject() { return m_pObject; }

protected:
    fw::GameObject* m_pObject;
};

class AddFromGameEvent : public fw::Event
{
public:
    AddFromGameEvent()
    {
    }
    virtual ~AddFromGameEvent() {}

    static const char* GetStaticEventType() { return "AddFromGameEvent"; }
    virtual const char* GetType() override { return GetStaticEventType(); }


protected:

};

class GameOverFromEvent : public fw::Event
{
public:
    GameOverFromEvent()
    {

    }
    virtual ~GameOverFromEvent() {}

    static const char* GetStaticEventType() { return "GameOverFromEvent"; }
    virtual const char* GetType() override { return GetStaticEventType(); }

protected:
};

class GameWinFromEvent : public fw::Event
{
public:

    GameWinFromEvent() {

    }
    virtual ~GameWinFromEvent() {}

    static const char* GetStaticEventType() { return "GameWinFromEvent"; }
    virtual const char* GetType() { return GetStaticEventType(); }

protected:

};

class LevelWinFromEvent : public fw::Event
{
public:
    LevelWinFromEvent() {}
    virtual ~LevelWinFromEvent() {}

    static const char* GetStaticEventType() { return "LevelWinFromEvent"; }
    virtual const char* GetType() { return GetStaticEventType(); }
protected:

};

class ResetFromEvent : public fw::Event {
public:
    ResetFromEvent() {}
    virtual ~ResetFromEvent() {}

    static const char* GetStaticEventType() { return "ResetFromEvent"; }
    virtual const char* GetType() { return GetStaticEventType(); }

protected:

};

class MenuFromEvent : public fw::Event {
public:
    MenuFromEvent() {}
    virtual ~MenuFromEvent() {}

    static const char* GetStaticEventType() { return "MenuFromEvent"; }
    virtual const char* GetType() { return GetStaticEventType(); }

protected:

};
