#ifndef TREE_H
#define TREE_H

#include "BinNode.h"
#include <iostream>
#include <cstring>

using namespace std;

class Tree
{
public:
    BinNode* root;

public:
    Tree();
    ~Tree();
    bool add(char* );
    BinNode* insertBranch(char* );
    void removeAll(BinNode* );
};

Tree::Tree()
{
    root=new BinNode(0);
}

BinNode* Tree::insertBranch(char *a)         //将一组O1串插入树枝边 
{
    int len=strlen(a);
    BinNode* node=root;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='0')
        {
            if(!node->lChild)
            {
                node=node->insertAsLC(1);
            }
            else node=node->lChild;
        }
        else
        {
            if(!node->rChild)
            {
                node=node->insertAsRC(1);
            }
            else node=node->rChild;
        }
    }
    return node;
}

bool Tree::add(char *a)          //函数先对新的一串加入树后，自底而上更新节点的胜负性 
{
    BinNode* node=insertBranch(a);
    if(node->lChild||node->rChild)
        return root->data;
    int tmp1=0,tmp2=0;
    while(node=node->parent)
    {
        if(node->lChild)
        {
            tmp1=node->lChild->data;
        }
        else tmp1=0;
        if(node->rChild)
        {
            tmp2=node->rChild->data;
        }
        else tmp2=0;
        if(tmp1 || tmp2) node->data=0;
        else node->data=1;
    }
    if(root->lChild && root->lChild->data) return root->data=1;
    if(root->rChild && root->rChild->data) return root->data=1;
    return root->data=0;

}

Tree::~Tree()
{
    removeAll(root);
}

void Tree::removeAll(BinNode * node)
{
    BinNode* lnode=node->lChild;
    BinNode* rnode=node->rChild;
    delete node;
    if(lnode) removeAll(lnode);
    if(rnode) removeAll(rnode);

}

#endif // TREE_H
