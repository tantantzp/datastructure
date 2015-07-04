#ifndef PQ_MIN_H
#define PQ_MIN_H

#include "Vector.h"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

bool ltt(int a,int b){return a>b;}
bool ltt(char a,char b){return (int)a>(int)b;}


#define  Node(PQ, i)       ((PQ)[i])
#define  InHeap(n, i)      (((-1) < (i)) && ((i) < (n)))
#define  Parent(i)         ((i-1) >> 1) //PQ[i]�ĸ��ڵ㣨floor((i-1)/2)��i����������
#define  LastInternal(n)   Parent(n-1)
#define  LChild(i)         (1 + ((i) << 1)) //PQ[i]������
#define  RChild(i)         ((1 + (i)) << 1) //PQ[i]���Һ���
#define  ParentValid(i)    (0 < i) //�ж�PQ[i]�Ƿ��и���
#define  LChildValid(n, i) InHeap(n, LChild(i))
#define  RChildValid(n, i) InHeap(n, RChild(i))
#define  Smaller(PQ, i, j)  (ltt(Node(PQ, i), Node(PQ, j)) ? j : i) //ȡ���ߣ���ʱǰ�����ȣ�
#define  ProperParent2(PQ, n, i) \
            (RChildValid(n, i) ? Smaller(PQ, Smaller(PQ, i, LChild(i)), RChild(i)) : \
            (LChildValid(n, i) ? Smaller(PQ, i, LChild(i)) : i \
            ) \
            ) //���ӣ����ࣩ�����еĴ��ߣ����ʱ���ڵ��ţ�

template <typename T>
class PQ_min                //С���ѣ��������ݽṹ�̲�ʵ��
{
public:
    Vector<T>* heap;
    int M; //����

    PQ_min(int m)
    {
        heap=new Vector<T>(m);
        M=m;
    }
    PQ_min(T* E,int n,int m=10000)
    {
        heap=new Vector<T>(heapify(E,n),n);
        M=m;
    }

    PQ_min(Vector<T>* p,int m=10000)
    {
        T* tmp=new T[p->size];
        for(int i=0;i<p->size;i++)
        {
            tmp[i]=(*p)[i];
        }
        heap=new Vector<T>(heapify(tmp,p->size),p->size);
        delete tmp;
        M=m;
    }
    ~PQ_min(){ delete heap; }

    int size() {return heap->size;}
    bool empty() {return heap->empty();}
    void insert(T e);                //���뱣֤�������������ֵ
    T getMin();
    T delMin();

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

#include "PQ_min_implementation.h"

#endif // PQ_MIN_H
