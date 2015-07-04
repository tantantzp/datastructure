#ifndef RTREE_IMPLEMENTATION_H
#define RTREE_IMPLEMENTATION_H

#include "RTree.h"
#include <iostream>
#include "cstdlib"
#include "cstdio"

using namespace std;

y_list::y_list(y_list* a,y_list* b)     //将两个y_list类归并
{
    size=a->size+b->size;
    p=new int[size];
    int len1=a->size,len2=b->size;
    int i=0,j=0,k=0;
    while((i<len1)&&(j<len2))
    {
        while((i<len1)&&(j<len2)&&(points[a->p[i]].y<=points[b->p[j]].y))
        {
            p[k++]=a->p[i++];
        }
        while((i<len1)&&(j<len2)&&(points[a->p[i]].y>points[b->p[j]].y))
        {
            p[k++]=b->p[j++];
        }
    }
    while(i<len1) p[k++]=a->p[i++];
    while(j<len2) p[k++]=b->p[j++];
    add();
}

void y_list::add()          //生成sum数组,sum[i]表示前i项和
{
    sum=new long long[size];
    sum[0]=points[p[0]].temperature;

    for(int i=1;i<size;i++)
    {
        sum[i]=sum[i-1]+points[p[i]].temperature;
    }
}

void y_list::y_sort(int lo, int hi) {    //对y排序，采用快排算法
    if (hi-lo < 2) return;
   int mi = partition_y(lo, hi-1);
   y_sort(lo, mi);
   y_sort(mi+1, hi);
}

int y_list::partition_y(int lo,int hi) {
   swap(p[lo], p[lo + rand() % (hi-lo+1)]);
   int pivot = p[lo];
   while (lo < hi) {
       while ((lo < hi) && (points[pivot].y <= points[p[hi]].y)) hi--;
      p[lo] = p[hi];
      while ((lo < hi) && (points[p[lo]].y <=points[pivot].y)) lo++;
      p[hi] = p[lo];
   }
   p[lo] = pivot;
   return lo;
}

long long y_list::search(int start, int end,int& num)
{
    int a=y_search(start-1)+1;
    int b=y_search(end);
    num+=b-a+1;
    if(a<=b)
    {
        return (sum[b]-sum[a])+points[p[a]].temperature;    //运用sum数组在O(1)时间内求和
    }
    else
    {
        return 0;
    }
}

int  y_list::y_search(int y)       //二分查找，返回不大于y的最大值
{
   int lo=0,hi=size;
   while (lo < hi) {
      int mi = (lo + hi) >> 1;
      (y < points[p[mi]].y) ? hi = mi : lo = mi + 1;
   }
   return --lo;
}

Node::Node(int a,int b)     //采用递归构造根节点，仅当当前节点为叶节点时返回，采用归并算法自底向上构造y_list
{
    start=points[a].x,end=points[b].x;
    int mi=(a+b)/2;
    if(a==b)
    {
        lnode=NULL;
        rnode=NULL;
        list=new y_list(a,b);
        return;
    }
    lnode=new Node(a,mi);
    rnode=new Node(mi+1,b);
    list=new y_list(lnode->list,rnode->list);
}

void Node::search(int& x1, int& x2,int& y1,int& y2,long long &result,int& number)
{
    if(x2<start || x1>end)         //查找区域与当前区域交集必为空
    {
        return;
    }
    if(x1<=start && x2>=end)        //当前区域包含于查找区域，可知其中所有点均满足，累加计数
    {
        result+=list->search(y1,y2,number);
        return;
    }
    lnode->search(x1,x2,y1,y2,result,number);     //否则递归划分，在孩子节点中找
    rnode->search(x1,x2,y1,y2,result,number);
}

long long RTree::search(int& x1, int& y1, int& x2, int& y2)
{
    long long result=0;
    int number=0;
    root->search(x1,x2,y1,y2,result,number);
    if(number!=0)
    {
        return result/number;
    }
    return 0;
}

#endif // RTREE_IMPLEMENTATION_H
