#ifndef LISTNODE_IMPLEMENTATION_H
#define LISTNODE_IMPLEMENTATION_H

#pragma once

//���������ܵ�ʵ�ֲο������ݽṹ�̲��е�ʵ�� 

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
