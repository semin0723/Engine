#include "ButtonClicked.h"
#include "../../../../../Components.h"

ButtonClicked::ButtonClicked(const std::string& name)
{
	_stateName = name;
}

ButtonClicked::~ButtonClicked()
{
}

void ButtonClicked::StateEnter()
{
	ButtonComponent* btn = componentManager->GetComponent<ButtonComponent>(_owner);
	if(btn->_onclick) btn->_onclick();

	btn->ChangeState(Button_State::Released);
}

void ButtonClicked::StateUpdate(float dt)
{
}

void ButtonClicked::StateExit()
{
}
