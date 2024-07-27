#pragma once
#include "State.h"

class ButtonClicked :
    public State
{
public:
    ButtonClicked(const std::string& name);
    virtual ~ButtonClicked();

    virtual void StateEnter();
    virtual void StateUpdate(float dt);
    virtual void StateExit();

};

