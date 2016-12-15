#ifndef TREENODE_H
#define TREENODE_H

#include <QObject>

class TreeNode : public QObject
{
    Q_OBJECT

public:
    explicit TreeNode(int key, QObject *parent = 0);
    virtual ~TreeNode();
    virtual void display();
    int key();

protected:
    int _key;

public:
    TreeNode *lchild;
    TreeNode *rchild;
};

#endif // TREENODE_H
