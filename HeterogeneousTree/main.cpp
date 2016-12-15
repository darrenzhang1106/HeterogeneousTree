#include <QtCore/QCoreApplication>
#include "treenode.h"
#include "integertreenode.h"
#include "stringtreenode.h"
#include "sorttree.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    SortTree *sTree = new SortTree();

    TreeNode *node1 = new IntegerTreeNode(33, 23);
    TreeNode *node2 = new StringTreeNode(12, "Tree Node A");
    TreeNode *node3 = new IntegerTreeNode(2, 2345);
    TreeNode *node4 = new StringTreeNode(30, "Tree Node B");
    TreeNode *node5 = new IntegerTreeNode(4, 23);
    TreeNode *node6 = new StringTreeNode(5, "Tree Node C");
    TreeNode *node7 = new IntegerTreeNode(7, 244);
    TreeNode *node8 = new StringTreeNode(9, "Tree Node R");
    TreeNode *node9 = new IntegerTreeNode(33, 23);
    //node1->display();
    //node2->display();

    sTree->addNode(node1);
    sTree->addNode(node2);
    sTree->addNode(node3);
    sTree->addNode(node4);
    sTree->addNode(node5);
    sTree->addNode(node6);
    sTree->addNode(node7);
    sTree->addNode(node8);
    sTree->addNode(node9);

    sTree->display();
    sTree->deleteNode(5);
    sTree->display();

    //system("PAUSE");

    return app.exec();
}
