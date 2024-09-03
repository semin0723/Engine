#pragma once
#include "BaseBTNode.h"
#include "BtStatus.h"

class RandomSelectorNode :public BaseBTNode
{
public:
	RandomSelectorNode(std::string name = "RandomSelectorNode") { Name = name; }
	~RandomSelectorNode() {}

	bool SetChildNodeProbability(UINT idx, float probability);
	void AttachChild(BaseBTNode* node);
	void AttachChildAt(BaseBTNode* node, UINT index);
	bool DetachChild(std::string nodeName);
	void DetachChildAt(UINT index);

private:
	std::vector<float> ChildNodeProbaility;
	std::vector<BaseBTNode*> Childs;
};

