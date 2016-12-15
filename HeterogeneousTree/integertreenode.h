#ifndef INTEGERTREENODE_H
#define INTEGERTREENODE_H
#include "treenode.h"
class IntegerTreeNode : public TreeNode
{
public:
    IntegerTreeNode(int key, int value);
    void display();

private:
    int _data;
};

#endif // INTEGERTREENODE_H
