#pragma once
#include "../../../../State/State.h"

class ButtonNormal :
    public State
{
public:
    ButtonNormal(const std::string& name);
    virtual ~ButtonNormal();

    virtual void StateEnter();
    virtual void StateUpdate(float dt);
    virtual void StateExit();

};

