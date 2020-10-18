#pragma once

namespace fw {

    class Event {
    public:
        Event();
        virtual ~Event();

        virtual const char* GetType() = 0;

    protected:
    };
}

    //enum class DeviceType
    //{
    //    Keyboard,
    //};

    //enum class DeviceState
    //{
    //    Pressed,
    //    Released
    //};

    //class InputEvent : public Event {
    //public:
    //    InputEvent()
    //    {
    //    }

    //    virtual ~InputEvent() { }

    //    static const char* GetStaticEventType()
    //    {
    //        return "InputEvent";
    //    }
    //    virtual const char* GetType() override
    //    {
    //        return GetStaticEventType();
    //    }


    //protected:
    //    DeviceType m_DeviceType;
    //    DeviceState m_DeviceState;
    //    unsigned int m_KeyCode;
    //};