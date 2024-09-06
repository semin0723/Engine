#include "pch.h"
#include "InputSystem.h"
#include "ECBase.h"
#include "GameEvents.h"

InputSystem::InputSystem() : _keyState(256, false)
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::Update(float dt)
{
	UpdateMouse(dt);

	HWND hWnd = GetFocus();
	if (hWnd == nullptr) return;

	for (int i = 0; i < 256; i++) {
		if (GetAsyncKeyState(i) & 0x8000) {
			if (_keyState[i] == false) {
				_keyState[i] = true;
				Engine->SendEvent<KeyDown>("Input", i, dt);
				Engine->RecordLog(std::format("KeyCode Pressed {}", i));
			}
			else {
				//Engine->SendEvent<Key>(i, dt);
			}
		}
		else {
			if (_keyState[i] == true) {
				_keyState[i] = false;
				//Engine->SendEvent<KeyUp>(i, dt);
			}
		}
	}
}

void InputSystem::UpdateMouse(float dt)
{
	static float accumulateTime;
	_prevMouseState = _curMouseState;

	POINT pos;
	GetCursorPos(&pos);
	HWND curWindow = GetFocus();

	ScreenToClient(curWindow, &pos);

	_curMouseState._position.x = (FLOAT)pos.x;
	_curMouseState._position.y = (FLOAT)pos.y;

	accumulateTime += dt;
	if (accumulateTime >= _throttleInverval) {
		accumulateTime -= _throttleInverval;
		//Engine->SendEvent<MouseMove>(_curMouseState._position);
	}

	_curMouseState._mouseLButton = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	_curMouseState._mouseRButton = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;

	// MouseButtonDown
	if (_prevMouseState._mouseLButton == false && _curMouseState._mouseLButton == true) {
		//Engine->SendEvent<MouseButtonDown>(VK_LBUTTON, _curMouseState._position, dt);
	}
	else if (_prevMouseState._mouseRButton == false && _curMouseState._mouseRButton == true) {
		//Engine->SendEvent<MouseButtonDown>(VK_RBUTTON, _curMouseState._position, dt);
	}

	// MouseButton
	if (_prevMouseState._mouseLButton == true && _curMouseState._mouseLButton == true) {
		//Engine->SendEvent<MouseButton>(VK_LBUTTON, _curMouseState._position, dt);
	}
	else if (_prevMouseState._mouseRButton == true && _curMouseState._mouseRButton == true) {
		//Engine->SendEvent<MouseButton>(VK_RBUTTON, _curMouseState._position, dt);
	}

	// MouseButtonUp
	if (_prevMouseState._mouseLButton == true && _curMouseState._mouseLButton == false) {
		//Engine->SendEvent<MouseButtonUp>(VK_LBUTTON, _curMouseState._position, dt);
	}
	else if (_prevMouseState._mouseRButton == true && _curMouseState._mouseRButton == false) {
		//Engine->SendEvent<MouseButtonUp>(VK_RBUTTON, _curMouseState._position, dt);
	}
}
