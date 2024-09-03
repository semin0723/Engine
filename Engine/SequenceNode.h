#pragma once
#include "BTStatus.h"
#include "BaseBTNode.h"

class SequenceNode : public BaseBTNode
{
public:
	SequenceNode(std::string name = "SequenceNode") { Name = name; }
	~SequenceNode() {}

	void AttachChild(BaseBTNode* node);
	void AttachChildAt(BaseBTNode* node, UINT index);
	bool DetachChild(std::string nodeName);
	void DetachChildAt(UINT index);

private:
	std::vector<BaseBTNode*> Childs;
};

