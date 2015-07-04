#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Tree.h"

using namespace std;

int main()
{
    int N;
    scanf("%d\n",&N);
    Tree tree;
    char a[65];
    int person=1;
    int tmp1=1,tmp2=1;
    gets(a);
    person=tree.add(a);
    for(int i=2;i<=N;i++)
    {
        gets(a);
        if(person==tree.add(a))           //每加入一串数字，调用add函数，根据树根结果判断胜负 
        {
            tmp2=i;
        }
        else
        {
            if(person==1)
            {
                printf("Adam %d %d\n",tmp1,tmp2);
            }
            else
            {
                printf("Eve %d %d\n",tmp1,tmp2);

            }
            person=1-person;
            tmp1=tmp2=i;
        }
    }
    if(person==1)
    {
        printf("Adam %d %d\n",tmp1,tmp2);
    }
    else
    {
        printf("Eve %d %d\n",tmp1,tmp2);
    }


    return 0;
}

