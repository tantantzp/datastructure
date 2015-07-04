#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#pragma once
#include <iostream>
#include "Vector.h" //引入向量
#include "List.h"
#include "Stack.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483647

using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus;

struct Edge { //边对象（为简化起见，不再严格封装）
   int i,j;
   EStatus status; //数据、权重、状态

   Edge(int ii,int jj, int w=0) :i(ii),j(jj), status(UNDETERMINED){} //构造新边
};

struct Vertex { //顶点对象（为简化起见，不再严格封装）
    int data;  VStatus status; //数据、出入度数、状态
    int dTime, fTime; //时间标签
    int parent; int priority;
    bool inStack;
    int tag;        //记录属于哪个强连通分量
    List<Edge*> edges;
    Vertex(int d) : //构造新顶点
        data(d), status(UNDISCOVERED),
        dTime(-1), fTime(-1), parent(-1),priority(0),tag(-1),inStack(false) {}
};

class GraphList{
public:
    int n; //顶点总数（编号从0至n-1）
    int e; //边总数
    Vector<Vertex*> V;
    void init(char* a,int N);
    GraphList()
    {
        n=0;e=0;
    }
    ~GraphList(){}

    void resetStatus(int a) ; //所有顶点、边的辅助信息复位,a控制priority

    void insert(char vertex);
    void insert(int j);
    void insert(int i,int j);
    int vertex(int i) {return V[i]->data;}

    ListNode<Edge*>* firstNbr(int i){ return V[i]->edges.first();}
    VStatus& status(int i){ return V[i]->status;}
    int& dTime(int i) {return V[i]->dTime;}
    int& fTime(int i) {return V[i]->fTime;}

    ListNode<Edge*>* exists(int v, int u); //边(v, u)是否存在
    EStatus& status(int v, int u) { return exists(v,u)->data->status;}//边(v, u)的状态

    int& parent(int v) { return V[v]->parent;}
    int& priority(int v) {return V[v]->priority;}

    void output()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<": "<<V[i]->data<<' '<<V[i]->priority<<' ';
            for(ListNode<Edge*>* e=firstNbr(i);e->succ!=NULL;e=e->succ)
            {
                cout<<e->data->i<<','<<e->data->j<<' ';
            }
            cout<<endl;
        }
    }


// 算法
    void BCC(int, int&,int&, Stack<int>&,GraphList*); //图的强连通分量分解，结果保存为一张新图
    void bcc(GraphList* graph);

    void SPFA(int );
    void SPFA_MAX(int );
    //void dijkstra(); //最短路径Dijkstra算法

};

#include "GraphList_implementation.h"
#endif
