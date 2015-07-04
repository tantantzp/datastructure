#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "PQ.h"
#include "PQ_min.h"
#include "Vector.h"
#include "Emission.h"
#include "cstring"

using namespace std;

int main()
{
    int N,Q,M;
    scanf("%d %d %d\n",&N,&Q,&M);
    int Num=N+Q;
    int a;
    char tmp1[20];
    Emission* emission=new Emission(M);    //创建Emission类
    for(int i=0;i<Num;i++)
    {
        gets(tmp1);              //手动解析输入，加快输入速度
        int len=strlen(tmp1);
        int j=0,a=0;
        bool f=false;
        if(tmp1[0]=='-')
        {
            j++;
            while(j<len)
            {
                a=a*10+(tmp1[j++]-'0');
            }
            a=-a;
        }
        else
        {
            while(j<len)
            {
                a=a*10+(tmp1[j++]-'0');
            }
        }

        if(a>0)                  //根据a的正负决定是插入或者查找
        {
            emission->insert(a);
        }
        else
        {
            emission->get(a);
        }

    }
    delete emission;

    return 0;
}

