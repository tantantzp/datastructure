#ifndef ZAUBERBERG_IMPLENENTATION_H
#define ZAUBERBERG_IMPLENENTATION_H
#pragma once

#include <iostream>
#include <stdio.h>
#include "zauberberg.h"

using namespace std;

bool life::operator < (life& l){return this->height<l.height;}
bool life::operator > (life& l){return this->height>l.height;}
bool life::operator >=(life& l){return this->health>=l.height;}
bool life::operator <=(life& l){return this->height<=l.height;}
ostream& operator<<(ostream& out,life& l)
{
    out<<l.height<<' '<<l.health<<endl;
    return out;
}

istream& operator>>(istream& in,life& l)
{
    in>>l.height>>l.health;
    return in;
}


void Berg::output(int lo, int hi)
{
    for(int i=lo;i<hi;i++)
    {
        cout<<elem[i];
    }
    cout<<endl;
}

void Berg::init()                        //�ú��������˼��������Զͬѧ���� 
{
    illNum=0;healthNum=0;
    for(int i=0;i<size;i++)
    {
        if(elem[i].health=='+')
            illNum++;
    }
    healthNum=lifeNum-illNum;

    healHeight=new int[healthNum+1];       //ʹ������洢�ض���Ŀ�����뼲����������Ӧ��ɽ�ĸ߶� 
    illHeight=new int[illNum+1];           //�Ӷ����ں�����λ�п���O(1)ʵ���ڿ���ȷ���߶ȷ�Χ 
    int htmp=0;
    int itmp=0;
    illHeight[0]=maxheight;
    for(int i=size-1;i>=0;i--)              //˳���ȡelem�е�������Ϣ,��ʼ��healHeight��illHeight 
    {
        if(elem[i].health=='-')
        {
            healHeight[++htmp]=elem[i].height;
        }
        else
        {
            illHeight[++itmp]=elem[i].height;
        }
    }
    healHeight[0]=healHeight[1]+1;
    healHeight[healthNum+1]=-1;
}

void Berg::caculate(double ph, double pf)     
{
    int itmp;
    if(ph<1&&ph>0)
    {
        itmp=illNum*ph+1;
    }
    else
    if(ph==1)
        itmp=illNum;
    else
        itmp=0;

    int htmp=healthNum*pf;
    int max=illHeight[itmp];
    int min=healHeight[htmp+1]+1;

    if(max>=min && max<=maxheight && min>=0)
    {
        printf("%d %d\n",min,max);
    }
    else printf("%d\n",-1);

}

int Berg::QSortPart(int low,int high)           //�����㷨 
{
    life key = elem[low];
    while(low<high)
    {
         while(low<high && elem[high].height>=key.height)--high;
         elem[low] = elem[high];
         while(low<high && elem[low].height<=key.height) ++ low;
         elem[high] =elem[low];

    }
    elem[low] = key;
    return low;
}

void Berg::QSort(int low,int high)
{
    if (low<high)
    {
         int KeyPos = QSortPart(low,high);
         QSort(low,KeyPos-1);
         QSort(KeyPos+1,high);
    }
}

#endif // ZAUBERBERG_IMPLENENTATION_H
