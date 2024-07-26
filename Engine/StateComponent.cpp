#include "pch.h"
#include "StateComponent.h"

StateComponent::StateComponent()
{
}

StateComponent::~StateComponent()
{
	for (auto& i : _states) {
		delete i.second;
	}
}

void StateComponent::Update(float dt)
{
	_states[_curStateName]->StateUpdate(dt);
}

void StateComponent::AddState(std::string& stateName, State* state)
{
	if (_states.find(stateName) == _states.end()) _states.insert({ stateName, state });
}

void StateComponent::RemoveState(std::string& stateName)
{
	delete _states[stateName];
	_states[stateName] = nullptr;
}

void StateComponent::ChangeState(std::string& prevStateName, std::string& curStateName)
{
	_states[_curStateName]->StateExit();
	_curStateName = curStateName;
	_states[_curStateName]->StateEnter();
}
