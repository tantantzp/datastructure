#ifndef GRAPHLIST_IMPLEMENTATION_H
#define GRAPHLIST_IMPLEMENTATION_H

#include "GraphList.h"
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "Route.h"

using namespace std;

void GraphList::resetStatus(){ //���ж��㡢�ߵĸ�����Ϣ��λ
  for (int i = 0; i < n; i++) { //����
      V[i]->status=0;
  }
  for(int i=0;i<e;i++) Estatus[i]=0;
}

void GraphList::insert(int nn, int *a, int k)
{
    V.insert(new Vertex(nn,a,k));
    n++;
}

void GraphList::insert(int nn,int l, int i, int j, int *a, int k)
{
    V[i]->edges.insertAsLast(new Edge(nn,l,i,j,a,k));
    V[j]->edges.insertAsLast(new Edge(nn,l,j,i,a,k));
    E.insert(new Edge(nn,l,i,j,a,k));
    e++;
}

ListNode<Edge*>* GraphList::exists(int v, int u)      //��(v, u)�Ƿ����
{
    for(ListNode<Edge*>* e=V[v]->edges.first();e->succ!=NULL;e=e->succ)
    {
        if(e->data->j==u) return e;
    }
    return NULL;
}

void GraphList::search(int start, int end, int *tmp)       //�����������ŵĽ� 
{
    clock=0;
    resetStatus();
    //sortEdge(tmp);
    Route route(K);
    route.s.push(start);
    route.lenth=0;
    V[start]->status++;
    V[end]->status++;
    findFirstRoute(end,tmp,route,-1,-1);          //����ȷ��һ�����н� 

    resetStatus();
    clock=0;
    Route route2(K);
    route2.s.push(start);
    route2.lenth=0;
    V[start]->status++;
    V[end]->status++;
    DFS(end,tmp,route2);                          //���û��ڼ�֦����������㷨�����ҵ����Ž� 
}

void GraphList::findFirstRoute(int end,int* tmp,Route& route,int oldEdge,int oldNode)
{
    int start=route.s.top();
    for(ListNode<Edge*>* e=firstNbr(start);e->succ!=NULL;e=e->succ)
    {
        if(isfind) return;
        if(Estatus[e->data->n]>0) continue;      //����û�����ʹ��ı� 
        int j=e->data->j;
        route.lenth+=e->data->lenth;
        if(Estatus[e->data->n]==0)
        {
            for(int i=0;i<K;i++)
			    route.score[i]+=e->data->score[i];
        }
        if(V[j]->status==0)
        {
            for(int i=0;i<K;i++)
                route.score[i]+=V[j]->score[i];
        }
        
        route.s.push(e->data->n);
        route.s.push(V[j]->n);
        Estatus[e->data->n]++;
        V[j]->status++;

        if(j==end)
        {
            bool flag=true;
            for(int i=0;i<K;i++)
            {
                if(route.score[i]<tmp[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)                   //�ҵ����н⣬��ջ 
            {
                 isfind=true;
                 best_Route->change(route,K);
                 return;
            }
        }
        findFirstRoute(end,tmp,route,e->data->n,start);   //�������� 
    }

    if(oldEdge<0 || oldNode<0 ) return;     //�Ըö�����������е㶼����������ԭ·���� 
    route.lenth+=E[oldEdge]->lenth;
    route.s.push(oldEdge);
    route.s.push(oldNode);
    Estatus[oldEdge]++;
    V[oldNode]->status++;
    return;
}

void GraphList::DFS(int end,int* tmp,Route& route)
{
    int start=route.s.top();
    for(ListNode<Edge*>* e=firstNbr(start);e->succ!=NULL;e=e->succ)  //ö�������ٱ� 
    {
        if(++clock>limit) return;                //����������������趨��Limit��ֹͣ���������ⳬʱ 
        int j=e->data->j;
        route.lenth+=e->data->lenth;
        if(route.lenth>best_Route->lenth)
        {
            route.lenth-=e->data->lenth;
            continue;
        }
        if(Estatus[e->data->n]>2)
        {
            route.lenth-=e->data->lenth;
            continue;
        }
        
        int* oldscore=new int[K];
        for(int i=0;i<K;i++)
            oldscore[i]=route.score[i];

        route.s.push(e->data->n);
        route.s.push(V[j]->n);

        if(Estatus[e->data->n]==0)
        {
            for(int i=0;i<K;i++)
            {
                route.score[i]+=e->data->score[i];

            }
        }
        if(V[j]->status==0)
        {
            for(int i=0;i<K;i++)
            {
                route.score[i]+=V[j]->score[i];
            }

        }
        
        Estatus[e->data->n]++;
        V[j]->status++;
        
        if(j==end)
        {
            bool flag=true;
            for(int i=0;i<K;i++)
            {
                if(route.score[i]<tmp[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                if(route.lenth<best_Route->lenth)       //�ҵ����Ž⣬��ջ���������� 
                {
                     best_Route->change(route,K);
                     route.s.pop();
                     route.s.pop();
                     for(int i=0;i<K;i++)
                         route.score[i]=oldscore[i];
                     route.lenth-=e->data->lenth;
                     Estatus[e->data->n]--;
                     V[j]->status--;
                     delete [] oldscore;
                     return;
                }
            }
        }
        
        DFS(end,tmp,route);                //���� 
        route.s.pop();                     //����·�� 
        route.s.pop();
        for(int i=0;i<K;i++)               //�ָ�·�߷��� 
            route.score[i]=oldscore[i];
        route.lenth-=e->data->lenth;
        Estatus[e->data->n]--;
        V[j]->status--;
        delete [] oldscore;
    }
}
#endif // GRAPHLIST_IMPLEMENTATION_H
