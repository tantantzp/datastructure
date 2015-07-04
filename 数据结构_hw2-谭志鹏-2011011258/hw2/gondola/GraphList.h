#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#pragma once
#include <iostream>
#include "Vector.h" //��������
#include "List.h"
#include "Stack.h"
#include "Route.h"
#define MAX_INT 2147483647

using namespace std;

struct Edge { //�߶���Ϊ������������ϸ��װ��
   int n;      //���
   int lenth;
   int i,j;
   int* score;
   //double priority;
   int status; //����·�г��ֵĴ���
   Edge(int nn,int l,int ii,int jj, int* a,int k)
       :n(nn),lenth(l),i(ii),j(jj),status(0)
   {
       score=new int[k];
       for(int i=0;i<k;i++)
       {
           score[i]=a[i];
       }
   }
   ~Edge()
   {
       delete []score;
   }
};

struct Vertex { //�������Ϊ������������ϸ��װ��
    int n;      //���
    int* score;
    int status; //���ֵĴ���
    //int dTime,fTime;
    List<Edge*> edges;
    Vertex(int nn,int* a,int k) :
        n(nn), status(0)
        //dTime(-1), fTime(-1)
    {
        score=new int[k];
        for(int i=0;i<k;i++)
        {
            score[i]=a[i];
        }
    }
    ~Vertex()
    {
        delete []score;
    }
};

class GraphList{
public:
    int n; //������������Ŵ�0��n-1��
    int e; //������
    int K;  //����ά��
    int* Estatus;   //�߳��ֵĴ������
    bool isfind;
    Vector<Vertex*> V;
    Vector<Edge*> E;
    Route* best_Route;
    long long clock;
    long long limit;
    GraphList(int k,int m,long long l)
    {
        isfind=false;
        n=0;e=0;
        K=k;
        best_Route=new Route(K);
        best_Route->lenth=MAX_INT;
        Estatus=new int[m];
        for(int i=0;i<m;i++) Estatus[i]=0;
        clock=0;
        limit=l;
    }
    ~GraphList()  {}

    void resetStatus() ; //���ж��㡢�ߵĸ�����Ϣ��λ
    void insert(int nn,int* a,int k);   //���붥��
    void insert(int nn,int l,int i,int j, int* a,int k);      //�����

    ListNode<Edge*>* firstNbr(int i){ return V[i]->edges.first();}

    int& status(int i){ return V[i]->status;}
    ListNode<Edge*>* exists(int v, int u); //��(v, u)�Ƿ����

    void output()
    {
        for(int i=0;i<n;i++)
        {
            cout<<V[i]->n<<' '<<V[i]->score[0]<<','<<V[i]->score[1]<<','<<V[i]->score[2]<<':';
            for(ListNode<Edge*>* e=firstNbr(i);e->succ!=NULL;e=e->succ)
            {
                cout<<e->data->n<<'_'<<e->data->lenth<<'_'<<e->data->j<<' ';
                  // <<e->data->score[0]<<','<<e->data->score[1]<<','<<e->data->score[2]<<' ';
            }
            cout<<endl;
        }
    }


// �㷨
    void sortEdge(int *tmp);
    void search(int start,int end,int* tmp);
    void findFirstRoute(int end,int *tmp,Route &route,int oldEdge,int oldNode);
    void DFS(int end,int* tmp,Route &route);
};
#include "GraphList_implementation.h"
#endif
