#pragma once
#include "pch.h"

typedef TypeId EventTypeId;

static const EventTypeId INVALID_EVENT_TYPE = INVALID_TYPE_ID;

class IEvent
{
public:
	IEvent(EventTypeId typeId) : _typeId(typeId) {}

	const EventTypeId GetEventTypeId() const { return _typeId; }

private:
	EventTypeId _typeId;
	std::string _sender;
};

