#pragma once
#include "Component.h"
#include "globalheader.h"
#include "State.h"

class StateComponent : public Component<StateComponent>
{
public:
	StateComponent();
	~StateComponent();

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt);
	void End() {}
	void Destroy() {}

	void AddState(std::string& stateName, State* state);
	void RemoveState(std::string& stateName);
	void ChangeState(std::string& prevStateName, std::string& curStateName);
	const std::string& GetCurStateName() const { return _curStateName; }

private:
	std::unordered_map<std::string, State*> _states;
	std::string _curStateName;

};

