#include "pch.h"
#include "SelectorNode.h"

void SelectorNode::AttachChild(BaseBTNode* node)
{
    Childs.push_back(node);
}

void SelectorNode::AttachChildAt(BaseBTNode* node, UINT index)
{
    Childs.insert(Childs.begin() + index, node);
}

bool SelectorNode::DetachChild(std::string nodeName)
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

    return true;
}

void SelectorNode::DetachChildAt(UINT index)
{
    delete Childs[index];
    Childs.erase(Childs.begin() + index);
}
