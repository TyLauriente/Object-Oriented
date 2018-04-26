#pragma once

#include <iostream>
#include "GameEventType.h"
using std::cout;
using std::endl;

class EventListener
{
public:
	EventListener() {}

	EventListener(GameEventType type) : m_eventType(type) {}

	~EventListener() {}

	void HandleEvent() { cout << "Listener::HandleEvent Type: " << (int)m_eventType << endl; }

	const GameEventType& GetEventType() const { return m_eventType; }

private:
	GameEventType m_eventType;
};