#ifndef HASHTABLE_IMPLEMENTATION_H
#define HASHTABLE_IMPLEMENTATION_H

#include <iostream>
#include "Hashtable.h"
#include "cstring"
using namespace std;

static size_t hashcode(char* s,int M,int len)//串的最小表示法，参考百度百科实现
{
    int l=len;
    int i = 0, j = 1, k = 0,t;
    while (i < l && j < l && k < l)   //找不到比它还小的或者完全匹配
    {
        t = s[(i+k)%l] - s[(j+k)%l];
        if (t == 0)
            k++;                  //相等的话,检测长度加1
        else
        {
            if (t > 0)            //大于的话,s[i]为首的肯定不是最小表示,最大表示就改<
                i += k + 1;
            else
                j += k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    int min=(i<j)?i:j;           //最小表示的位置

    char a[10001];
    strcpy(a,s);
    for(int m=0;m<l;m++)           //将字符串循环移位至最小表示位置
    {
        s[m]=a[(m+min)%l];
    }
    int h=0;
    int tmp=2;
    for (int m = 0; m < l; m++)     //将串进行顺序相关的散列
    {
       tmp=(tmp*2)%M;
       h=(h+tmp*(int)s[m])%M;
    }
    return (size_t)h;
}

Hashtable::Hashtable(int c, int l)
{
   M = c;
   N = 0; ht = new Entry*[M];
   Len=l;
   memset(ht, 0, sizeof(Entry*)*M);
}

Hashtable::~Hashtable()
{
   for (int i = 0; i < M; i++)
      if (ht[i]) delete ht[i];
   delete ht;
}

void Hashtable::put(char* k, int v)
{

   int r = hashcode(k,M,Len) % M;   //采用字符串自小表示法获取散列值
   if(!ht[r])                  //新的词条
   {
       printf("%d\n",0);
       ht[r]=new Entry(k,v);
       return;
   }
   while (ht[r]&&strcmp(k,ht[r]->key)!=0) {
      r = (r+1) % M;
   }

   if(!ht[r])            //新的词条
   {
       ht[r]=new Entry(k,v);
       printf("%d\n",0);
   }
   else
   {
       printf("%d\n",ht[r]->value);   //已存在的词条
   }

   return ;
}

#endif // HASHTABLE_IMPLEMENTATION_H
