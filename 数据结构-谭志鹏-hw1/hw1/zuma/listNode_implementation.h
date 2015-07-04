#ifndef LISTNODE_IMPLEMENTATION_H
#define LISTNODE_IMPLEMENTATION_H

#pragma once

//以下链表功能的实现参考了数据结构教材中的实现 

template<typename T>
ListNode<T>* ListNode<T>::insertAsPred(const T &e)
{
    ListNode<T>* x=new ListNode(e,pred,this);
    this->pred->succ=x;
    this->pred=x;
    return x;
}

template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(const T &e)
{
    ListNode<T>* x=new ListNode(e,this,succ);
    this->succ->pred=x;
    this->succ=x;
    return x;
}

#endif // LISTNODE_IMPLEMENTATION_H
