#ifndef ROUTE_H
#define ROUTE_H

#include "stdlib.h"
#include "cstdio"
#include "Vector.h"
#include "Stack.h"

using namespace std;

class Route                    //Â·¾¶¶ÔÏó 
{
public:
    Stack<int> s;
    int lenth;
    int* score;
    Route(int k=20):lenth(0)
    {
        score=new int[k];
        for(int i=0;i<k;i++) score[i]=0;
    }
    void change(Route r,int k);
    void output();
};

void Route::change(Route r,int k)
{
    while(!s.empty()) s.pop();
    for(int i=0;i<r.s.size;i++)
    {
        s.push(r.s[i]);
    }
    lenth=r.lenth;
    for(int i=0;i<k;i++)
    {
        score[i]=r.score[i];
    }
} 

void Route::output()
{
    for(int i=0;i<s.size;i++)
    {
        if(i%2==0)
        {
            printf("C%d ",s[i]);
        }
        else
        {
            printf("R%d ",s[i]);
        }
    }
    printf("\n");
}


#endif // ROUTE_H
