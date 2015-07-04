#ifndef PQ_IMPLEMENTATION_H
#define PQ_IMPLEMENTATION_H

#include "PQ.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>

using namespace std;

template <typename T>
int PQ<T>::percolateUP(Vector<T>* A,int i)
{
    while(ParentValid(i))
    {
        int j=Parent(i);
        if(lt(Node(*A,i),Node(*A,j))) break;
        swap(Node(*A,i),Node(*A,j));
        i=j;
    }
    return i;
}

template <typename T>
int PQ<T>::percolateDown(Vector<T>* A,int n,int i)
{
    int j;
    while(i !=(j=ProperParent(*A,n,i)))
    {
        swap(Node(*A,i),Node(*A,j));
        i=j;
    }
    return i;
}

template <typename T>
int PQ<T>::percolateDown(T* E,int n,int i)
{
    int j;
    while(i !=(j=ProperParent(E,n,i)))
    {
        swap(Node(E,i),Node(E,j));
        i=j;
    }
    return i;
}

template <typename T>
T* PQ<T>::heapify(T* E,int lo,int hi)       //Ω®∂—À„∑®
{
    for(int i=LastInternal(hi-lo);InHeap(hi-lo,i);i--)
    {
        percolateDown(E+lo,hi-lo,i);
    }
    return E;
}

template <typename T>
T* PQ<T>::heapify(T* E,int n)
{
    return heapify(E,0,n);
}

template<typename T>
T PQ<T>::getMax()
{
    return (*heap)[0];
}

template <typename T>
void PQ<T>::insert(T e)
{
    heap->insert(size(),e);
    percolateUP(heap,size()-1);
}

template <typename T>
T PQ<T>::delMax()
{
    T maxElem=(*heap)[0];
    if(size()==1)
    {
        heap->remove(1);
        return maxElem;
    }
    (*heap)[0]=heap->remove(size()-1);
    percolateDown(heap,size(),0);
    return maxElem;
}


#endif // PQ_IMPLEMENTATION_H
