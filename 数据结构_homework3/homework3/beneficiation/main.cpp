#include <iostream>
#include "beneficiation.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
    int N;
    srand((unsigned)time(NULL));
    while((N=GetNumOfOre())!=0)   //�����β�ѯ
    {
        Vector<int>* rock=new Vector<int>(N);
        for(int i=0;i<N;i++)
        {
            rock->insert(i);
        }

        Qsort(rock,0,N-1);    //���ÿ�������
        for(int i=N-1;i>=0;i--)
        {
            Report((*rock)[i],N-1-i);
        }

        delete rock;
    }
    return 0;
}

