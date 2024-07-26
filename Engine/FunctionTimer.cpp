#include "pch.h"
#include "FunctionTimer.h"

FunctionTimer* FunctionTimer::_instance = nullptr;

FunctionTimer* FunctionTimer::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new FunctionTimer;
	}
	return _instance;
}

void FunctionTimer::DestroyInstance()
{
	delete _instance;
	_instance = nullptr;
}

void FunctionTimer::Update(float dt)
{
	for (UINT i = 0; i < _timerFunctionTable.size(); i++) {
		if (!std::get<3>(_timerFunctionTable[i])) continue; // function empty

		// decrese interval
		std::get<0>(_timerFunctionTable[i]) -= dt;
		if (std::get<0>(_timerFunctionTable[i]) <= 0) {

			// action function
			std::get<3>(_timerFunctionTable[i])();

			// check repeat
			if (std::get<2>(_timerFunctionTable[i]) == true) {
				// repeat timer
				std::get<0>(_timerFunctionTable[i]) = std::get<1>(_timerFunctionTable[i]);
			}
			else {
				ClearTimer(i);
			}
		}
	}
}

void FunctionTimer::ClearTimer(ULL timerId)
{
	_timerFunctionTable[timerId] = { 0.f, 0.f, false, std::function<void()>() };
}
