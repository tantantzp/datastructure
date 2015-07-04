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

void Qsort(Vector<int>* rock,int s,int e)   //快速排序算法
{
    Vector<int> min;                //存比轴点小的数
    Vector<int> max;                //存比轴点大的数
    int N=e-s+1;
    int key=rand()%N;
    swap((*rock)[s],(*rock)[s+key]);    //随机选取轴点
    int i;
    for(i=s+1;i<s+N-2;i+=3)        //顺序将轴点与后续没三个数比较
    {
        int a,b,c,d;
        Measure((*rock)[s],(*rock)[i],(*rock)[i+1],(*rock)[i+2],&a,&b,&c,&d);
        if(a==-1)           //轴点最小
        {
            max.insert((*rock)[i]);
            max.insert((*rock)[i+1]);
            max.insert((*rock)[i+2]);
        }
        else if(a==1)        //轴点最大
        {
            min.insert((*rock)[i]);
            min.insert((*rock)[i+1]);
            min.insert((*rock)[i+2]);
        }
        else        //轴点居中
        {
            put((*rock)[s],(*rock)[i],b,&min,&max);
            put((*rock)[s],(*rock)[i+1],c,&min,&max);
            put((*rock)[s],(*rock)[i+2],d,&min,&max);    //去除最大最小的元素
            if(b==0)       //找出居中的另一个编号，将其归入下一次的比较中
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
    int remain=e-i+1;       //处理剩下的1个或者2个数

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
    for(int i=0;i<ms;i++)          //运用min和max序列更新数组，将轴点居中
    {
        (*rock)[s+i]=min[i];
    }
    for(int i=0;i<max.size;i++)
    {
        (*rock)[s+ms+1+i]=max[i];
    }
    if(ms>1)
    Qsort(rock,s,s+ms-1);        //递归调用，分别将左右两边数排序
    if(max.size>1)
    Qsort(rock,s+ms+1,e);
}



#endif // SORT_H
