#pragma once
#include "BTStatus.h"
#include "BaseBTNode.h"

class SelectorNode : public BaseBTNode
{
public:
	SelectorNode(std::string name = "SelectorNode") { Name = name; }
	~SelectorNode() {}

	void AttachChild(BaseBTNode* node);
	void AttachChildAt(BaseBTNode* node, UINT index);
	bool DetachChild(std::string nodeName);
	void DetachChildAt(UINT index);

private:
	std::vector<BaseBTNode*> Childs;
};

