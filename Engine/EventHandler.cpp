#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
	for (EventHandler::EventDispatcherMap::iterator it = _eventMap.begin(); it != _eventMap.end(); it++) {
		delete (*it).second;
	}
	_eventMap.clear();
}
