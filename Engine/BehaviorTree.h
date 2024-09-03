#pragma once
#include "BaseBTNode.h"

class BehaviorTree
{
public:
	BehaviorTree() {}
	~BehaviorTree() {}

	void Update(float dt);

	template <class T>
	BaseBTNode* CreateNode(std::string name) {
		BaseBTNode* newNode = new T(name);

		return newNode;
	}

	void SetRootNode(BaseBTNode* node) { Root = node; }


private:
	BaseBTNode* Root = nullptr;
};

