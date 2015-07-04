#ifndef PQ_MIN_IMPLEMENTATION_H
#define PQ_MIN_IMPLEMENTATION_H

#include "PQ_min.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>

using namespace std;

template <typename T>
int PQ_min<T>::percolateUP(Vector<T>* A,int i)
{
    while(ParentValid(i))
    {
        int j=Parent(i);
        if(ltt(Node(*A,i),Node(*A,j))) break;
        swap(Node(*A,i),Node(*A,j));
        i=j;
    }
    return i;
}

template <typename T>
int PQ_min<T>::percolateDown(Vector<T>* A,int n,int i)
{
    int j;
    while(i !=(j=ProperParent2(*A,n,i)))
    {
        swap(Node(*A,i),Node(*A,j));
        i=j;
    }
    return i;
}

template <typename T>
int PQ_min<T>::percolateDown(T* E,int n,int i)
{
    int j;
    while(i !=(j=ProperParent2(E,n,i)))
    {
        swap(Node(E,i),Node(E,j));
        i=j;
    }
    return i;
}

template <typename T>
T* PQ_min<T>::heapify(T* E,int lo,int hi)      //建堆算法
{
    for(int i=LastInternal(hi-lo);InHeap(hi-lo,i);i--)
    {
        percolateDown(E+lo,hi-lo,i);
    }
    return E;
}

template <typename T>
T* PQ_min<T>::heapify(T* E,int n)
{
    return heapify(E,0,n);
}

template<typename T>
T PQ_min<T>::getMin()
{
    return (*heap)[0];
}

template <typename T>
void PQ_min<T>::insert(T e)
{
    if(this->size()<M)
    {
        heap->insert(size(),e);
        percolateUP(heap,size()-1);
    }
    else                  //已经达到容量,弹出最小值
    {
       T tmp=getMin();
       if(e>tmp)
       {
           (*heap)[0]=e;
           percolateDown(heap,size(),0);
       }
    }
}

template <typename T>
T PQ_min<T>::delMin()
{
    T minElem=(*heap)[0];
    if(size()==1)
    {
        heap->remove(0);
        return minElem;
    }
    (*heap)[0]=heap->remove(size()-1);
    percolateDown(heap,size(),0);
    return minElem;
}

#endif // PQ_MIN_IMPLEMENTATION_H
