#pragma once
#include "BTStatus.h"

class AIComponent;

class BaseBTNode
{
public:
	BaseBTNode() = default;
	~BaseBTNode() = default;

	virtual void Initialize() = 0;
	virtual BTStatus Behave(float dt) = 0;

	const std::string& GetName() const { return Name; }
	void SetName(std::string& name) { Name = name; }
	const AIComponent* GetParent() const { return Parent; }
	void SetParent(AIComponent* parent) { Parent = parent; }

	BTStatus GetNodeState() const { return CurStatus; }

protected:
	std::string Name;
	BTStatus CurStatus = BTStatus::Default;
	AIComponent* Parent = nullptr;
};

