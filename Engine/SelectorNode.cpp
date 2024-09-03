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
    std::vector<BaseBTNode*>::iterator iterator = Childs.end();
    for (auto it = Childs.begin(); it != Childs.end(); it++) {
        if ((*it)->GetName() == nodeName) {
            iterator = it;
            break;
        }
    }
    if (iterator == Childs.end()) {
        return false;
    }

    Childs.erase(iterator);
    delete* iterator;

    return true;
}

void SelectorNode::DetachChildAt(UINT index)
{
    delete Childs[index];
    Childs.erase(Childs.begin() + index);
}
