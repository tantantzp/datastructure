#include <iostream>
#include "zauberberg.h"
#include <stdio.h>

using namespace std;

int N;
long H;
int M;

int main()
{
    scanf("%d %ld",&N,&H);
    Berg berg(N,H);
    long hei;
    char heal;
    for(int i=0;i<N;i++)
    {
        scanf("%ld %c",&hei,&heal);
        life tmp(hei,heal);
        berg.insert(tmp);      //insert可以动态扩容，分摊O(1) 
    }
    berg.QSort();             //生物按高度排序 
    scanf("%d",&M);
    double p1,p2;
    berg.init();              //初始化berg中记录高度的数组 
    for(int i=0;i<M;i++)
    {
        scanf("%lf %lf",&p1,&p2);
        berg.caculate(p1,p2);
    }
    return 0;
}
