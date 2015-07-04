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
    Emission* emission=new Emission(M);    //����Emission��
    for(int i=0;i<Num;i++)
    {
        gets(tmp1);              //�ֶ��������룬�ӿ������ٶ�
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

        if(a>0)                  //����a�����������ǲ�����߲���
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

