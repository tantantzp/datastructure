#ifndef HASHTABLE_IMPLEMENTATION_H
#define HASHTABLE_IMPLEMENTATION_H

#include <iostream>
#include "Hashtable.h"
#include "cstring"
using namespace std;

static size_t hashCode(char s[]) {      //散列函数
   int h = 0;
   int tmp=32;
   for (size_t n = strlen(s), i = 0; i < n; i++)
      {
       //tmp*=97;
      // h+=tmp*(int)s[i];
       h=h*132+(int)s[i];
   }
   return (size_t) h;
}

Hashtable::Hashtable(int c)
{
   M = c;
   N = 0; ht = new Entry*[M];
   memset(ht, 0, sizeof(Entry*)*M);
   Max.value=0;
}

Hashtable::~Hashtable()
{
   for (int i = 0; i < M; i++)
      if (ht[i]) delete ht[i];
   delete ht;
}

void Hashtable::put(char* k, int v)    //散列插入
{
   int r = hashCode(k) % M;
   while ((ht[r] && strcmp(k , ht[r]->key)!=0) ) {    //遇到冲突采用线性试探策略
      r = (r+1) % M;
   }
   if (ht[r])                    //名字已存在的情况
   {
       ht[r]->value+=v;
       if(ht[r]->value>Max.value)          //更新最大值
       {
           strcpy(Max.key,k);
           Max.value=ht[r]->value;
       }
       return ;
   }
   while (ht[r]) r = (r + 1) % M;
   ht[r] = new Entry(k, v); ++N;   //名字不存在的情况
   if(v>Max.value)
   {
       strcpy(Max.key,k);
       Max.value=v;
   }
   return ;
}
#endif // HASHTABLE_IMPLEMENTATION_H
