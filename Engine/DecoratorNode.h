#pragma once
#include "BaseBTNode.h"
#include "BTStatus.h"

class DecoratorNode : public BaseBTNode
{
public:
	DecoratorNode(std::string name = "DecoratorNode") { Name = name; }
	~DecoratorNode() {}

	void AddNode(BaseBTNode* node) { Child = node; }
	bool DeleteNode() { 
		delete Child;
		Child = nullptr; 
	}

private:
	BaseBTNode* Child;
};

