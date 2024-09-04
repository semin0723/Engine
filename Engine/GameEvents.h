#pragma once
#include "Event.h"

// Mouse Event
struct MouseButtonDown : public Event<MouseButtonDown> {

};

// Key Event
struct KeyDown : public Event<KeyDown> {
	int keyCode;
	float delta;

	KeyDown(int keyCode, float delta) : keyCode(keyCode), delta(delta) {}
};