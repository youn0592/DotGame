#include "FrameworkPCH.h"
#include "EventManager.h"
#include "Event.h"
#include "Core/GameCore.h"

fw::EventManager::EventManager()
{

}

fw::EventManager::~EventManager()
{

}

void fw::EventManager::AddEvent(Event* pEvent)
{
    m_EventQueue.push(pEvent);
}

void fw::EventManager::DispatchAllEvents(GameCore* pGameCore)
{
    while (m_EventQueue.empty() == false)
    {
        // Remove it from the queue.
        Event* pEvent = m_EventQueue.front();
        m_EventQueue.pop();

        // Send it to the game.
        pGameCore->OnEvent(pEvent);

        // Delete the event.
        delete pEvent;
    }
}
