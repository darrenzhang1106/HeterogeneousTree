#ifndef SORTTREE_H
#define SORTTREE_H

#include <QObject>
#include "treenode.h"
class SortTree : public QObject
{
    Q_OBJECT

public:
    explicit SortTree(QObject *parent = 0);
    void addNode(TreeNode *newNode);
    bool searchNodeByKey(TreeNode *searchNode, TreeNode **lastNode);
    bool deleteNode(int key);
    void display();

private:
    bool searchNodeInner(TreeNode *curNode, TreeNode *searchNode, TreeNode **lastNode);
    void travelLMR(TreeNode *curNode);
    bool deleteNodeInner(TreeNode **curNode, int key);
    bool deleteNodeSecond(TreeNode **curNode);

private:
    TreeNode *_root;
    
};

#endif // SORTTREE_H
