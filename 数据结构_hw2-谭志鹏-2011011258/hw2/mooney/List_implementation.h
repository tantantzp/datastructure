#ifndef LIST_IMPLEMENTATION_H
#define LIST_IMPLEMENTATION_H

#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
List<T>::List(const T* a)
{
    init();
    int i=0;
    while(a[i]!='\0')
    {
        insertAsLast(a[i++]);
    }
}

template <typename T>
void List<T>::init()
{
    header=new ListNode<T>;
    tailer=new ListNode<T>;
    header->succ=tailer; header->pred=NULL;
    tailer->pred=header; tailer->succ=NULL;
    _size=0;
}

template <typename T>
void List<T>::copyNodes(ListNode<T>* e,int n)
{
    init();
    while(n--)
    {
        insertAsLast(e->data);
        e=e->succ;
    }
}

template <typename T>
ListNode<T>* List<T>::operator[](int r)
{
    if(r>=_size) return last();
    if(r<_size>>1)
    {
        ListNode<T>* p=first();
        while(0<r--) p=p->succ;
        return p;
    }
    else
    {
        ListNode<T>* p=last();
        while(0<r--) p=p->pred;
        return p;
    }
}

template <typename T>
int List<T>::clear()
{
    int oldSize=_size;
    while(0<_size) remove(header->succ);
    return oldSize;
}

template <typename T>
T List<T>::remove(ListNode<T>* p)
{
    T e=p->data;
    p->pred->succ=p->succ;
    p->succ->pred=p->pred;
    delete p;_size--;
    return e;
}

template <typename T>
T List<T>::remove(int r)
{
    ListNode<T>* p=first();
    while(0<r--) p=p->succ;
    return remove(p);
}

template <typename T>
void List<T>::remove(ListNode<T> *start, ListNode<T> *end)
{
    ListNode<T>* p;
    while(start!=end)
    {
        p=start;
        start=start->succ;
        remove(p);
    }
    remove(end);
}

template <typename T>
ListNode<T>* List<T>::insertAsFirst(const T &e)
{
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAsLast(const T &e)
{
    _size++;
    return tailer->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T> *p, const T &e)
{
    _size++;
    return p->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T> *p, const T &e)
{
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAt(int r,T const& e)
{
    if(r>_size)
    {
        return insertAsLast(e);
    }
    if(r<_size>>1)
    {
        ListNode<T>* p=header;
        while(0<r--) p=p->succ;
        _size++;
        return p->insertAsSucc(e);
    }
    else
    {
        ListNode<T>* p=tailer;
        r=_size-r;
        while(0<r--) p=p->pred;
        _size++;
        return p->insertAsPred(e);
    }
}

template <typename T>
void List<T>::output()
{
    ListNode<T>* p=first();
    int n=_size;
    if(n==0) {cout<<"-"<<endl;return;}
    while(0<n--)
    {
        cout<<p->data<<' ';
        p=p->succ;
    }
    cout<<endl;
}




#endif // LIST_IMPLEMENTATION_H
