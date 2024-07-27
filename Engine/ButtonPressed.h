#pragma once
#include "State.h"

class ButtonPressed :
    public State
{
public:
    ButtonPressed(const std::string& name);
    virtual ~ButtonPressed();

    virtual void StateEnter();
    virtual void StateUpdate(float dt);
    virtual void StateExit();
};

