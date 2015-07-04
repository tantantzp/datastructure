#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#pragma once
#include <iostream>
#include "Vector.h" //��������
#include "List.h"
#include "Stack.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483647

using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus;

struct Edge { //�߶���Ϊ������������ϸ��װ��
   int i,j;
   EStatus status; //���ݡ�Ȩ�ء�״̬

   Edge(int ii,int jj, int w=0) :i(ii),j(jj), status(UNDETERMINED){} //�����±�
};

struct Vertex { //�������Ϊ������������ϸ��װ��
    int data;  VStatus status; //���ݡ����������״̬
    int dTime, fTime; //ʱ���ǩ
    int parent; int priority;
    bool inStack;
    int tag;        //��¼�����ĸ�ǿ��ͨ����
    List<Edge*> edges;
    Vertex(int d) : //�����¶���
        data(d), status(UNDISCOVERED),
        dTime(-1), fTime(-1), parent(-1),priority(0),tag(-1),inStack(false) {}
};

class GraphList{
public:
    int n; //������������Ŵ�0��n-1��
    int e; //������
    Vector<Vertex*> V;
    void init(char* a,int N);
    GraphList()
    {
        n=0;e=0;
    }
    ~GraphList(){}

    void resetStatus(int a) ; //���ж��㡢�ߵĸ�����Ϣ��λ,a����priority

    void insert(char vertex);
    void insert(int j);
    void insert(int i,int j);
    int vertex(int i) {return V[i]->data;}

    ListNode<Edge*>* firstNbr(int i){ return V[i]->edges.first();}
    VStatus& status(int i){ return V[i]->status;}
    int& dTime(int i) {return V[i]->dTime;}
    int& fTime(int i) {return V[i]->fTime;}

    ListNode<Edge*>* exists(int v, int u); //��(v, u)�Ƿ����
    EStatus& status(int v, int u) { return exists(v,u)->data->status;}//��(v, u)��״̬

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


// �㷨
    void BCC(int, int&,int&, Stack<int>&,GraphList*); //ͼ��ǿ��ͨ�����ֽ⣬�������Ϊһ����ͼ
    void bcc(GraphList* graph);

    void SPFA(int );
    void SPFA_MAX(int );
    //void dijkstra(); //���·��Dijkstra�㷨

};

#include "GraphList_implementation.h"
#endif
