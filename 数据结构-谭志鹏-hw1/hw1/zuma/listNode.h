#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

//以下链表节点类的实现参考了数据结构教材中的实现 

template <typename T>
class ListNode
{
public:
    T data;
    ListNode<T>* pred;
    ListNode<T>* succ;

    ListNode(){}
    ListNode(T d,ListNode<T>* p,ListNode<T>* s)
        :data(d),pred(p),succ(s){}
    ListNode<T>* insertAsPred(T const& e);
    ListNode<T>* insertAsSucc(T const& e);
};

#include "listNode_implementation.h"


#endif // LISTNODE_H
