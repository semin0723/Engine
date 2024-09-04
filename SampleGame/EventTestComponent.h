#pragma once
#include "EngineHeader.h"

class EventTestComponent : Component<EventTestComponent> {
public:
	EventTestComponent() {}
	~EventTestComponent() {}

	void Initialize();

	void OnButtonDown(const KeyDown* event);
private:

};


