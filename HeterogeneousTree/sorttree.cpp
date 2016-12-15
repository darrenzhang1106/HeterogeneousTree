#include "sorttree.h"
#include <iostream>
SortTree::SortTree(QObject *parent) :
    QObject(parent),
    _root(NULL)
{
}

void SortTree::addNode(TreeNode *newNode)
{
    TreeNode *lastNode = NULL;
    // 不存在相同健值的节点
    if(!searchNodeByKey(newNode, &lastNode))
    {
        if(_root == NULL)
        {
            _root = newNode;
        }
        else if(newNode->key() > lastNode->key())
        {
            lastNode->rchild = newNode;
        }
        else
        {
            lastNode->lchild = newNode;
        }
        std::cout << "成功添加节点：" << newNode->key() << std::endl;
    }
    else
    {
        std::cout << "不能添加" << newNode->key() << ",该键值已经存在!"  << std::endl;
    }
}

bool SortTree::searchNodeByKey(TreeNode *searchNode, TreeNode **lastNode)
{
    // 树为空
    if(_root == NULL)
    {
        *lastNode = _root;
        return false;
    }
    return  searchNodeInner(_root, searchNode, lastNode);
}

bool SortTree::deleteNode(int key)
{
    if(_root == NULL)
    {
        return false;
    }
    std::cout << "删除节点:" << key << std::endl;
    return deleteNodeInner(&_root, key);
}

void SortTree::display()
{
    std::cout << "中序遍历如下：" << std::endl;
    if(_root == NULL)
    {
        std::cout << "NULL Tree"<< std::endl;
        return;
    }

    travelLMR(_root);
}

bool SortTree::searchNodeInner(TreeNode *curNode, TreeNode *searchNode, TreeNode **lastNode)
{
    // 找到键值 一样大的节点
    if(curNode->key() == searchNode->key())
    {
        return true;
    }
    // 查找键值>当前遍历节点键值
    else if(searchNode->key() > curNode->key())
    {

        if(!curNode->rchild)
        {
            *lastNode = curNode;
            return false;
        }
        return searchNodeInner(curNode->rchild, searchNode, lastNode);//遍历左子树
    }
    // 查找键值<当前遍历节点键值
    else
    {
        if(!curNode->lchild)
        {
            *lastNode = curNode;
            return false;
        }
        return searchNodeInner(curNode->lchild, searchNode, lastNode);//遍历右子树
    }
}

void SortTree::travelLMR(TreeNode *curNode)
{
    if(curNode->lchild) travelLMR(curNode->lchild);
    if(curNode) curNode->display();
    if(curNode->rchild) travelLMR(curNode->rchild);
}

bool SortTree::deleteNodeInner(TreeNode **curNode, int key)
{
    if((*curNode) == NULL) return false;
    //找到节点并删除节点
    if((*curNode)->key() == key) return deleteNodeSecond(curNode);
    else if((*curNode)->key() < key ) return deleteNodeInner(&((*curNode))->rchild, key);
    else  return deleteNodeInner(&((*curNode)->lchild), key);
}

bool SortTree::deleteNodeSecond(TreeNode **curNode)
{
    TreeNode *tempNode;
    TreeNode *tempNode2;
    if(!(*curNode)->rchild)
    {
        //没有右子树，直接接上左子树即可
        tempNode = *curNode;
        *curNode=(*curNode)->lchild;
        delete tempNode;
    }
    else if(!(*curNode)->lchild)
    {
        //没有左子树，直接接上右子树即可
        tempNode = *curNode;
        *curNode=(*curNode)->rchild;
        delete tempNode;
    }
    else
    {
        //既有左子树右有右子树，直接接上左子树。遍历左孩子的(右子树*)，接上右子树
        tempNode = *curNode;
        //遍历到左孩子
        tempNode2 = (*curNode)->lchild;
        //遍历到左孩子的(右子树*)
        while(tempNode2->rchild) tempNode2 = tempNode2->rchild;
        //接上右子树
        tempNode2->rchild = tempNode->rchild;
        //直接接上左子树
        tempNode = tempNode->lchild;

        delete *curNode;
    }
    return true;
}
