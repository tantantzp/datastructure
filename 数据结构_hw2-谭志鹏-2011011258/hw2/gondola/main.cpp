#include "GraphList.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    long long limit=10000+(int)sqrt(N*M)*200000;     //设定循环上限，控制搜索时间 
    GraphList* graph=new GraphList(K,M,limit);
    int *tmp=new int[K];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp[j]);
        }
        graph->insert(i,tmp,K);
    }
    for(int i=0;i<M;i++)
    {
        int len,ii,jj;
        scanf("%d %d %d",&len,&ii,&jj);
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp[j]);
        }
        graph->insert(i,len,ii,jj,tmp,K);
    }

    int start,end;
    scanf("%d %d",&start,&end);
    for(int i=0;i<K;i++)
        scanf("%d",&tmp[i]);

    graph->search(start,end,tmp);          //查找尽可能短的路 
    graph->best_Route->output();
    
    delete graph;
    delete tmp;
    return 0;
}
