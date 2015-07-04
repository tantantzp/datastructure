#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "GraphList.h"
#include "cstring"
//#include <fstream>

using namespace std;

//ifstream fin;


int main()
{
    //fin.open("4.in");
    int N,E;
    scanf("%d %d",&N,&E);
    //fin>>N>>E;
    //cout<<N<<' '<<E<<endl;

    char* a=new char[N+1];
    cin>>a;
    //fin>>a;
    GraphList* graph=new GraphList();
    graph->init(a,N);
    for(int i=0;i<E;i++)
    {
        int v,u;
        scanf("%d %d",&v,&u);
        //fin>>v>>u;
        graph->insert(v,u);

    }
    graph->SPFA(0);
    cout<<graph->V[N-1]->priority<<endl;
    GraphList* ngraph=new GraphList();
    graph->bcc(ngraph);
    //ngraph->output();
    ngraph->SPFA_MAX(ngraph->n-1);
    cout<<ngraph->V[0]->priority<<endl;
    //fin.close();
    delete []a;
    delete graph;
    delete ngraph;
    return 0;
}


