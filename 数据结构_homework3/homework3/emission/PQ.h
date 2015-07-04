#ifndef PQ_H
#define PQ_H

#include "Vector.h"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

bool lt(int a,int b){return a<b;}
bool lt(char a,char b){return (int)a<(int)b;}


#define  Node(PQ, i)       ((PQ)[i])
#define  InHeap(n, i)      (((-1) < (i)) && ((i) < (n)))
#define  Parent(i)         ((i-1) >> 1) //PQ[i]的父节点（floor((i-1)/2)，i无论正负）
#define  LastInternal(n)   Parent(n-1)
#define  LChild(i)         (1 + ((i) << 1)) //PQ[i]的左孩子
#define  RChild(i)         ((1 + (i)) << 1) //PQ[i]的右孩子
#define  ParentValid(i)    (0 < i) //判断PQ[i]是否有父亲
#define  LChildValid(n, i) InHeap(n, LChild(i))
#define  RChildValid(n, i) InHeap(n, RChild(i))
#define  Bigger(PQ, i, j)  (lt(Node(PQ, i), Node(PQ, j)) ? j : i) //取大者（等时前者优先）
#define  ProperParent(PQ, n, i) \
            (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : \
            (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : i \
            ) \
            ) //父子（至多）三者中的大者（相等时父节点优）

template <typename T>
class PQ                 //大根堆参照数据结构教材实现
{
public:
    Vector<T>* heap;

    PQ()
    {
        heap=new Vector<T>;
    }
    PQ(T* E,int n)
    {
        heap=new Vector<T>(heapify(E,n),n);
    }
    PQ(Vector<T>* p)
    {
        T* tmp=new T[p->size];
        for(int i=0;i<p->size;i++)
        {
            tmp[i]=(*p)[i];
        }
        heap=new Vector<T>(heapify(tmp,p->size),p->size);
        delete tmp;
    }

    ~PQ(){ delete heap; }

    int size() {return heap->size;}
    bool empty() {return heap->empty();}
    void insert(T e);
    T getMax();
    T delMax();

    T* heapify(T* E,int lo,int hi);
    T* heapify(T* E,int n);
    int percolateUP(Vector<T>* A,int i);
    int percolateDown(Vector<T>* A,int n,int i);
    int percolateDown(T* E,int n,int i);
    void output()
    {
        heap->output();
    }
};


#include "PQ_implementation.h"

#endif // PQ_H
