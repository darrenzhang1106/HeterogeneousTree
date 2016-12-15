#include "treenode.h"

TreeNode::TreeNode(int key, QObject *parent) :
    QObject(parent),
    _key(key),
    lchild(NULL),
    rchild(NULL)
{
}

TreeNode::~TreeNode()
{
}

void TreeNode::display()
{
}

int TreeNode::key()
{
    return _key;
}


