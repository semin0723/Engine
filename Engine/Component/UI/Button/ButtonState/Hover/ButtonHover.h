#pragma once
#include "../../../../State/State.h"

class ButtonHover : public State
{
public:
	ButtonHover(const std::string& name);
	virtual ~ButtonHover();

	virtual void StateEnter();
	virtual void StateUpdate(float dt);
	virtual void StateExit();
};

