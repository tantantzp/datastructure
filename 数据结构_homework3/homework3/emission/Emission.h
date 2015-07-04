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
    PQ_min<int>* min_heap;      //����һ��С����
    int M;                       //���������ΪM
    Emission(int m)
    {
        M=m;
        min_heap=new PQ_min<int>(m);
    }
    ~Emission()
    {
        delete min_heap;
    }

    void insert(int a)        //����
    {
        min_heap->insert(a);
    }
    void get(int a)           //��ѯʱ��С��ת��Ϊ����ѣ�Ȼ�����
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
