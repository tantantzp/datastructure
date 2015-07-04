#ifndef HASHTABLE_IMPLEMENTATION_H
#define HASHTABLE_IMPLEMENTATION_H

#include <iostream>
#include "Hashtable.h"
#include "cstring"
using namespace std;

static size_t hashcode(char* s,int M,int len)//������С��ʾ�����ο��ٶȰٿ�ʵ��
{
    int l=len;
    int i = 0, j = 1, k = 0,t;
    while (i < l && j < l && k < l)   //�Ҳ���������С�Ļ�����ȫƥ��
    {
        t = s[(i+k)%l] - s[(j+k)%l];
        if (t == 0)
            k++;                  //��ȵĻ�,��ⳤ�ȼ�1
        else
        {
            if (t > 0)            //���ڵĻ�,s[i]Ϊ�׵Ŀ϶�������С��ʾ,����ʾ�͸�<
                i += k + 1;
            else
                j += k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    int min=(i<j)?i:j;           //��С��ʾ��λ��

    char a[10001];
    strcpy(a,s);
    for(int m=0;m<l;m++)           //���ַ���ѭ����λ����С��ʾλ��
    {
        s[m]=a[(m+min)%l];
    }
    int h=0;
    int tmp=2;
    for (int m = 0; m < l; m++)     //��������˳����ص�ɢ��
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

   int r = hashcode(k,M,Len) % M;   //�����ַ�����С��ʾ����ȡɢ��ֵ
   if(!ht[r])                  //�µĴ���
   {
       printf("%d\n",0);
       ht[r]=new Entry(k,v);
       return;
   }
   while (ht[r]&&strcmp(k,ht[r]->key)!=0) {
      r = (r+1) % M;
   }

   if(!ht[r])            //�µĴ���
   {
       ht[r]=new Entry(k,v);
       printf("%d\n",0);
   }
   else
   {
       printf("%d\n",ht[r]->value);   //�Ѵ��ڵĴ���
   }

   return ;
}

#endif // HASHTABLE_IMPLEMENTATION_H
