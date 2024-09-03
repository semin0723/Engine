#include "pch.h"
#include "BehaviorTree.h"

void BehaviorTree::Update(float dt)
{
	if (Root->GetNodeState() != BTStatus::Running) {
		Root->Initialize();
	}
	Root->Behave(dt);
}
