#include <iostream>
#include "stdio.h"
#include "cstring"
#include "stdlib.h"
#include "Hashtable.h"

using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    Hashtable* table=new Hashtable(N*5,M);    //创建散列表

    for(int i=1;i<=N;i++)
    {
       char a[10001];
       scanf("%s",a);
       table->put(a,i);        //插入散列表
    }

    delete table;
    return 0;
}

