#ifndef HASHTABLE_IMPLEMENTATION_H
#define HASHTABLE_IMPLEMENTATION_H

#include <iostream>
#include "Hashtable.h"
#include "cstring"
using namespace std;

static size_t hashCode(char s[]) {      //ɢ�к���
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

void Hashtable::put(char* k, int v)    //ɢ�в���
{
   int r = hashCode(k) % M;
   while ((ht[r] && strcmp(k , ht[r]->key)!=0) ) {    //������ͻ����������̽����
      r = (r+1) % M;
   }
   if (ht[r])                    //�����Ѵ��ڵ����
   {
       ht[r]->value+=v;
       if(ht[r]->value>Max.value)          //�������ֵ
       {
           strcpy(Max.key,k);
           Max.value=ht[r]->value;
       }
       return ;
   }
   while (ht[r]) r = (r + 1) % M;
   ht[r] = new Entry(k, v); ++N;   //���ֲ����ڵ����
   if(v>Max.value)
   {
       strcpy(Max.key,k);
       Max.value=v;
   }
   return ;
}
#endif // HASHTABLE_IMPLEMENTATION_H
