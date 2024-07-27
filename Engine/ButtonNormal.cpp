#include "ButtonNormal.h"
#include "Components.h"

ButtonNormal::ButtonNormal(const std::string& name)
{
	_stateName = name;
}

ButtonNormal::~ButtonNormal()
{
}

void ButtonNormal::StateEnter()
{
	Sprite* sp = componentManager->GetComponent<Sprite>(_owner);
	sp->_spriteId = (L"Images\\Button\\"  + componentManager->GetComponent<ButtonComponent>(_owner)->_name + StringToWstring(_stateName));
}

void ButtonNormal::StateUpdate(float dt)
{
}

void ButtonNormal::StateExit()
{
}
