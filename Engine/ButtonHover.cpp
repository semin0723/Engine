#include "ButtonHover.h"
#include "Components.h"

ButtonHover::ButtonHover(const std::string& name)
{
	_stateName = name;
}

ButtonHover::~ButtonHover()
{
}

void ButtonHover::StateEnter()
{
	Sprite* sp = ComponentManager->Getcomponent<Sprite>(_owner);
	sp->GetImage(L"Images\\Button\\" + ComponentManager->Getcomponent<ButtonComponent>(_owner)->_name + StringToWstring(_stateName));
}

void ButtonHover::StateUpdate(float dt)
{
}

void ButtonHover::StateExit()
{
}
