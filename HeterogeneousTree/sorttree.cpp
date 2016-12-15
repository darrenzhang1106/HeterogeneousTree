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
    // ��������ͬ��ֵ�Ľڵ�
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
        std::cout << "�ɹ���ӽڵ㣺" << newNode->key() << std::endl;
    }
    else
    {
        std::cout << "�������" << newNode->key() << ",�ü�ֵ�Ѿ�����!"  << std::endl;
    }
}

bool SortTree::searchNodeByKey(TreeNode *searchNode, TreeNode **lastNode)
{
    // ��Ϊ��
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
    std::cout << "ɾ���ڵ�:" << key << std::endl;
    return deleteNodeInner(&_root, key);
}

void SortTree::display()
{
    std::cout << "����������£�" << std::endl;
    if(_root == NULL)
    {
        std::cout << "NULL Tree"<< std::endl;
        return;
    }

    travelLMR(_root);
}

bool SortTree::searchNodeInner(TreeNode *curNode, TreeNode *searchNode, TreeNode **lastNode)
{
    // �ҵ���ֵ һ����Ľڵ�
    if(curNode->key() == searchNode->key())
    {
        return true;
    }
    // ���Ҽ�ֵ>��ǰ�����ڵ��ֵ
    else if(searchNode->key() > curNode->key())
    {

        if(!curNode->rchild)
        {
            *lastNode = curNode;
            return false;
        }
        return searchNodeInner(curNode->rchild, searchNode, lastNode);//����������
    }
    // ���Ҽ�ֵ<��ǰ�����ڵ��ֵ
    else
    {
        if(!curNode->lchild)
        {
            *lastNode = curNode;
            return false;
        }
        return searchNodeInner(curNode->lchild, searchNode, lastNode);//����������
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
    //�ҵ��ڵ㲢ɾ���ڵ�
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
        //û����������ֱ�ӽ�������������
        tempNode = *curNode;
        *curNode=(*curNode)->lchild;
        delete tempNode;
    }
    else if(!(*curNode)->lchild)
    {
        //û����������ֱ�ӽ�������������
        tempNode = *curNode;
        *curNode=(*curNode)->rchild;
        delete tempNode;
    }
    else
    {
        //����������������������ֱ�ӽ������������������ӵ�(������*)������������
        tempNode = *curNode;
        //����������
        tempNode2 = (*curNode)->lchild;
        //���������ӵ�(������*)
        while(tempNode2->rchild) tempNode2 = tempNode2->rchild;
        //����������
        tempNode2->rchild = tempNode->rchild;
        //ֱ�ӽ���������
        tempNode = tempNode->lchild;

        delete *curNode;
    }
    return true;
}
