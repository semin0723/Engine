#include "ButtonPressed.h"
#include "Components.h"

ButtonPressed::ButtonPressed(const std::string& name)
{
	_stateName = name;
}

ButtonPressed::~ButtonPressed()
{
}

void ButtonPressed::StateEnter()
{
	Sprite* sp = ComponentManager->Getcomponent<Sprite>(_owner);
	sp->GetImage(L"Images\\Button\\" + ComponentManager->Getcomponent<ButtonComponent>(_owner)->_name + StringToWstring(_stateName));
}

void ButtonPressed::StateUpdate(float dt)
{
}

void ButtonPressed::StateExit()
{
}
