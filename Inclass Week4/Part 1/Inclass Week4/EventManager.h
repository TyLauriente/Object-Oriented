#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <map>
#include <list>
#include "GameEventType.h"
#include "EventListener.h"
using std::map;
using std::list;

class EventManager
{
public:
	EventManager() {}

	~EventManager() {}

	void Register(GameEventType type, const EventListener& listener);
	void Dispatch(GameEventType type);

private:
	map < GameEventType, list<EventListener>> m_ListenersByEventType;
};

void EventManager::Register(GameEventType type, const EventListener& listener)
{
	//map<GameEventType, list<EventListener>>::iterator it = m_ListenersByEventType.begin();
	bool entryFound = false;
	auto it = m_ListenersByEventType.begin();
	for (; it != m_ListenersByEventType.end(); ++it)
	{
		// If we have an entry add it to the list.
		if (it->first == type)
		{
			it->second.push_back(listener);
			entryFound = true;
		}
	}

	if (!entryFound)
	{
		list<EventListener> listeners;
		listeners.push_back(listener);
		m_ListenersByEventType.insert(std::make_pair(type, listeners));
	}
}

void EventManager::Dispatch(GameEventType type)
{
	auto it = m_ListenersByEventType.begin();

	for (; it != m_ListenersByEventType.end(); ++it)
	{
		if (it->first == type)
		{
			auto eventIt = it->second.begin();
			for (; eventIt != it->second.end(); ++eventIt)
			{
				eventIt->HandleEvent();
			}
		}
	}
}

#endif