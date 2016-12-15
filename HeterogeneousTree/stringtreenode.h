#ifndef STRINGTREENODE_H
#define STRINGTREENODE_H
#include <cstring>
#include <iostream>
#include "treenode.h"
class StringTreeNode : public TreeNode
{
public:
    StringTreeNode(int key, std::string value);
    void display();

private:
    std::string _data;
};

#endif // STRINGTREENODE_H
