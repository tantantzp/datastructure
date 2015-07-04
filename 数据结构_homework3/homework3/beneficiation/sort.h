#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "beneficiation.h"
#include "vector.h"
#include "cstdlib"
#include "cstdio"
#include <ctime>

using namespace std;

void put(int key,int i,int a,Vector<int>* min,Vector<int>* max)
{
    if(a==-1)
    {
        min->insert(i);
    }
    else
    if(a==1)
    {
       max->insert(i);
    }
}

void Qsort(Vector<int>* rock,int s,int e)   //���������㷨
{
    Vector<int> min;                //������С����
    Vector<int> max;                //����������
    int N=e-s+1;
    int key=rand()%N;
    swap((*rock)[s],(*rock)[s+key]);    //���ѡȡ���
    int i;
    for(i=s+1;i<s+N-2;i+=3)        //˳����������û�������Ƚ�
    {
        int a,b,c,d;
        Measure((*rock)[s],(*rock)[i],(*rock)[i+1],(*rock)[i+2],&a,&b,&c,&d);
        if(a==-1)           //�����С
        {
            max.insert((*rock)[i]);
            max.insert((*rock)[i+1]);
            max.insert((*rock)[i+2]);
        }
        else if(a==1)        //������
        {
            min.insert((*rock)[i]);
            min.insert((*rock)[i+1]);
            min.insert((*rock)[i+2]);
        }
        else        //������
        {
            put((*rock)[s],(*rock)[i],b,&min,&max);
            put((*rock)[s],(*rock)[i+1],c,&min,&max);
            put((*rock)[s],(*rock)[i+2],d,&min,&max);    //ȥ�������С��Ԫ��
            if(b==0)       //�ҳ����е���һ����ţ����������һ�εıȽ���
            {
                (*rock)[i+2]=(*rock)[i];
            }
            else if(c==0)
            {
                (*rock)[i+2]=(*rock)[i+1];
            }
            i--;
        }
    }
    int remain=e-i+1;       //����ʣ�µ�1������2����

    if(remain==1)
    {
        int a,b,c,d;
        Measure((*rock)[s],(*rock)[s+N-1],-1,-1,&a,&b,&c,&d);
        if(b==1)
        {
            max.insert((*rock)[s+N-1]);
        }
        else
        {
            min.insert((*rock)[s+N-1]);
        }
    }
    else if(remain==2)
    {
        int a,b,c,d;
        Measure((*rock)[s],(*rock)[s+N-1],(*rock)[s+N-2],-1,&a,&b,&c,&d);
        if(a==-1)
        {
            max.insert((*rock)[s+N-2]);
            max.insert((*rock)[s+N-1]);
        }
        else if(a==1)
        {
            min.insert((*rock)[s+N-2]);
            min.insert((*rock)[s+N-1]);
        }
        else
        {
            if(b==1)
            {
                max.insert((*rock)[s+N-1]);
                min.insert((*rock)[s+N-2]);
            }
            else
            {
                max.insert((*rock)[s+N-2]);
                min.insert((*rock)[s+N-1]);
            }
        }
    }
    int ms=min.size;
    (*rock)[s+ms]=(*rock)[s];
    for(int i=0;i<ms;i++)          //����min��max���и������飬��������
    {
        (*rock)[s+i]=min[i];
    }
    for(int i=0;i<max.size;i++)
    {
        (*rock)[s+ms+1+i]=max[i];
    }
    if(ms>1)
    Qsort(rock,s,s+ms-1);        //�ݹ���ã��ֱ���������������
    if(max.size>1)
    Qsort(rock,s+ms+1,e);
}



#endif // SORT_H
