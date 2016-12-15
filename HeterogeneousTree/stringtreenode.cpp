#include "stringtreenode.h"
#include <iostream>
StringTreeNode::StringTreeNode(int key, std::string value):
    TreeNode(key),
    _data(value)
{
}

void StringTreeNode::display()
{
    std::cout << "key:" << this->key() << " data:" << _data << std::endl;
}
