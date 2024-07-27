#include "ButtonReleased.h"
#include "../../../../../Components.h"

ButtonReleased::ButtonReleased(const std::string& name)
{
	_stateName = name;
}

ButtonReleased::~ButtonReleased()
{
}

void ButtonReleased::StateEnter()
{
}

void ButtonReleased::StateUpdate(float dt)
{
	static float accumulateTime;
	accumulateTime += dt;
	if (accumulateTime >= _stateChangeInterval) {
		accumulateTime = 0;
		ButtonComponent* btn = componentManager->GetComponent<ButtonComponent>(_owner);
		btn->ChangeState(Button_State::Normal);
	}
}

void ButtonReleased::StateExit()
{
}
