#include <iostream>
#include <stdio.h>
#include <cstring>
#include "QuickSort.h"

using namespace std;

void output(char** dir,int n);

void print(char** dir,int i,int j, int deep);

int main()
{
    int N;
    scanf("%d\n",&N);

    char** dir;
    dir=new char*[N];
    for(int i=0;i<N;i++)
    {
        dir[i]=new char[260];
    }
    for(int i=0;i<N;i++)
    {
        gets(dir[i]);
    }

    QuickSort(dir,0,N-1);

    output(dir,N);

    for(int i=0;i<N;i++)
    {
        delete []dir[i];
    }
    delete dir;

    return 0;
}

void print(char **dir, int i, int j,int deep)
{

    while(dir[i][j]!='\0')
    {
        if(dir[i][j]!='/')
        {
            cout<<dir[i][j++];
        }
        else
        {
            printf("\n");
            deep++;
            for(int k=0;k<deep;k++)
                printf("  ");
            j++;
        }
    }
}

void output(char **dir, int n)        //将排序后的结果根据题目要求输出 
{
    int i=0;
    while(i<n)
    {
        int j=0;
        int deep=0;
        print(dir,i,j,deep);

        while(++i<n)
        {
             deep=0;
             for(j=0; ;j++)
             {
                 if(dir[i-1][j]=='\0')
                 {
                     if(dir[i][j]=='/'||dir[i][j]=='\0')
                     {
                         deep++;
                     }
                     break;
                 }
                 if(dir[i][j]=='\0')
                 {
                     break;
                 }
                 if(dir[i-1][j]=='/'&& dir[i][j]=='/')
                 {
                     deep++;
                 }
                 else
                 {
                     if(dir[i-1][j]!=dir[i][j])
                         break;
                 }
             }
             if(!deep)
             {
                 printf("\n");
                 break;
             }
             while(dir[i][j]!='/')
             {
                 --j;
             }
             j++;
             printf("\n");
             for(int k=0;k<deep;k++)
                 printf("  ");
             print(dir,i,j,deep);

        }
    }
}

