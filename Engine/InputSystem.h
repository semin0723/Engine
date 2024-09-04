#pragma once
#include "globalheader.h"
#include "ECMain.h"

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	void Update(float dt);

	class Mouse {
	public:
		D2D1_POINT_2F _position = { 0, 0 };

		bool _mouseLButton = false;
		bool _mouseRButton = false;
	};

	void UpdateMouse(float dt);


private:
	std::vector<bool> _keyState;
	Mouse _curMouseState;
	Mouse _prevMouseState;
	float _throttleInverval = 0.01667f;

};

