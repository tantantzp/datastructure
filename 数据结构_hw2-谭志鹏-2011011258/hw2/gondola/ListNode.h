#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

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


#endif // LISTNODE_H
