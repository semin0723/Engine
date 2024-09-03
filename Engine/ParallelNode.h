#pragma once
#include "BTStatus.h"
#include "BaseBTNode.h"

class ParallelNode : public BaseBTNode
{
public:
	ParallelNode(std::string name = "ParallelNode") { Name = name; }
	~ParallelNode() {}

	void AttachChild(BaseBTNode* node);
	void AttachChildAt(BaseBTNode* node, UINT index);
	bool DetachChild(std::string nodeName);
	void DetachChildAt(UINT index);

private:
	std::vector<BaseBTNode*> Childs;
};

