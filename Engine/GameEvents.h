#pragma once
#include "Event.h"

// Mouse Event
struct MouseButtonDown : Event<MouseButtonDown> {

};

// Key Event
struct KeyDown : Event<KeyDown> {
	int keyCode;
	float delta;

	KeyDown(int keyCode, float delta) : keyCode(keyCode), delta(delta) {}
};