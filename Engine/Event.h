#pragma once
#include "IEvent.h"

template<class T>
class Event :
    public IEvent
{
public:
    static const EventTypeId EVENT_TYPE_ID;

    Event() : IEvent(EVENT_TYPE_ID) {}

private:

};

template<class T>
const EventTypeId Event<T>::EVENT_TYPE_ID   { typeid(T).hash_code() };