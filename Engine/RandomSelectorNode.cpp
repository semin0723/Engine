#include "pch.h"
#include "RandomSelectorNode.h"

bool RandomSelectorNode::SetChildNodeProbability(UINT idx, float probability)
{
    if (idx >= Childs.size()) return false;

    ChildNodeProbaility[idx] = probability;

    return true;
}

void RandomSelectorNode::AttachChild(BaseBTNode* node)
{
    Childs.push_back(node);
    ChildNodeProbaility.push_back(0);
}

void RandomSelectorNode::AttachChildAt(BaseBTNode* node, UINT index)
{
    Childs.insert(Childs.begin() + index, node);
    ChildNodeProbaility.insert(ChildNodeProbaility.begin() + index, 0);
}

bool RandomSelectorNode::DetachChild(std::string nodeName)
{
    std::vector<BaseBTNode*>::iterator iterator;
    for (auto it = Childs.begin(); it != Childs.end(); it++) {
        if ((*it)->GetName() == nodeName) {
            iterator = it;
        }
    }
    if (iterator == Childs.end()) {
        return false;
    }

    delete* iterator;
    Childs.erase(iterator);
    ChildNodeProbaility.erase(ChildNodeProbaility.begin() + (iterator - Childs.begin()));

    return true;
}

void RandomSelectorNode::DetachChildAt(UINT index)
{
    delete Childs[index];
    Childs.erase(Childs.begin() + index);
    ChildNodeProbaility.erase(ChildNodeProbaility.begin() + index);
}
