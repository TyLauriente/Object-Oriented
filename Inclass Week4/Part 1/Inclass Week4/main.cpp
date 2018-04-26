#include <iostream>
#include"EventManager.h"

int main()
{
	EventManager em;
	EventListener el(GameEventType::Explosion);

	em.Register(el.GetEventType(), el);

	em.Dispatch(GameEventType::Explosion);

	system("pause");
	return 0;
}