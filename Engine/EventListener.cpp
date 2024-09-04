#include "pch.h"
#include "EventListener.h"
#include "ECMain.h"

EventListener::EventListener()
{
}

EventListener::~EventListener()
{
	UnRegisterAllCallbacks();
}

void EventListener::UnRegisterAllCallbacks()
{
	//for (auto& delegate : _callbacks) {
	//	Engine->UnSubscribeEvent(delegate);
	//}
	_callbacks.clear();
}
