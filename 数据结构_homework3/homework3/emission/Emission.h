#ifndef EMISSION_H
#define EMISSION_H

#include "PQ.h"
#include "PQ_min.h"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"

using namespace std;

class Emission
{
public:
    PQ_min<int>* min_heap;      //包含一个小根堆
    int M;                       //堆最大容量为M
    Emission(int m)
    {
        M=m;
        min_heap=new PQ_min<int>(m);
    }
    ~Emission()
    {
        delete min_heap;
    }

    void insert(int a)        //插入
    {
        min_heap->insert(a);
    }
    void get(int a)           //查询时将小堆转化为大根堆，然后求和
    {
        int num=-a;
        PQ<int> max_heap(min_heap->heap);
        unsigned long long sum=0;
        for(int i=0;i<num;i++)
        {
            sum+=max_heap.delMax();
        }
        printf("%ld\n",sum);
        //cout<<sum<<endl;
    }

};




#endif // EMISSION_H
