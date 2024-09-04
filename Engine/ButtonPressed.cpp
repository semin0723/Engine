#include "pch.h"
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
	Sprite* sp = componentManager->GetComponent<Sprite>(_owner);
	sp->SetSpriteId(L"Images\\Button\\" + componentManager->GetComponent<ButtonComponent>(_owner)->_name + StringToWstring(_stateName));
}

void ButtonPressed::StateUpdate(float dt)
{
}

void ButtonPressed::StateExit()
{
}
