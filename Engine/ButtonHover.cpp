#include "pch.h"
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
	Sprite* sp = componentManager->GetComponent<Sprite>(_owner);
	sp->SetSpriteId(L"Images\\Button\\" + componentManager->GetComponent<ButtonComponent>(_owner)->_name + StringToWstring(_stateName));
}

void ButtonHover::StateUpdate(float dt)
{
}

void ButtonHover::StateExit()
{
}
