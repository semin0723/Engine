#pragma once
#include "State.h"

class ButtonReleased :
    public State
{
public:
    ButtonReleased(const std::string& name);
    virtual ~ButtonReleased();

    virtual void StateEnter();
    virtual void StateUpdate(float dt);
    virtual void StateExit();

private:
    float _stateChangeInterval = 0.05f;
};

