#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>
using namespace std;

template<typename T>
class List
{
private:
    int _size;
    ListNode<T>* header;
    ListNode<T>* tailer;
protected:
    void init();
    void copyNodes(ListNode<T>* e,int n);


public:
    List(){init();}
    List(List<T> & L){copyNodes(L.first(),L.size());}
    List(List<T> & L,int r,int n){copyNodes(L[r],n);}
    List(ListNode<T> p,int n){copyNodes(p,n);}
    List(const T* a);

    ~List(){clear();delete header;delete tailer;}

    int clear();
    int size() const{return _size;}
    bool empty() const{return _size<=0;}
    ListNode<T>* first(){return header->succ;}
    ListNode<T>* last(){return tailer->pred;}

    ListNode<T>* insertAsFirst(T const& e);
    ListNode<T>* insertAsLast(T const& e);
    ListNode<T>* insertBefore(ListNode<T>* p,T const& e);
    ListNode<T>* insertAfter(ListNode<T>* p,T const& e);
    ListNode<T>* insertAt(int r,T const& e);
    ListNode<T>* operator[](int r);

    T remove(ListNode<T>* p);
    T remove(int r);
    void remove(ListNode<T>* start,ListNode<T>* end);
    void output();
};


#include "List_implementation.h"

#endif // LIST_H
