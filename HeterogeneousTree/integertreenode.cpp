#include "integertreenode.h"
#include <iostream>
IntegerTreeNode::IntegerTreeNode(int key, int value):
    TreeNode(key),
    _data(value)
{
}

void IntegerTreeNode::display()
{
    std::cout << "key:" << this->key() << " value:" << this->_data << std::endl;
}
