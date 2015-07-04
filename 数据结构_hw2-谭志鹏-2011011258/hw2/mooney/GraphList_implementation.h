#ifndef GRAPHLIST_IMPLEMENTATION_H
#define GRAPHLIST_IMPLEMENTATION_H

#include "GraphList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

void GraphList::init(char *a,int N)
{
    for(int i=0;i<N;i++)
    {
        insert(a[i]);
    }
}

void GraphList::resetStatus(int a){ //所有顶点、边的辅助信息复位
  for (int i = 0; i < n; i++) { //顶点
      V[i]->status=UNDISCOVERED;
      V[i]->dTime=V[i]->fTime=-1;
      V[i]->parent=-1;
      if(a>0)
          V[i]->priority = INT_MAX;
      else V[i]->priority=INT_MIN;
      for (ListNode<Edge*>* e=firstNbr(i);e->succ!=NULL;e=e->succ) //边
         e->data->status=UNDETERMINED;
  }
}

void GraphList::insert(int j)
{
    V.insert(new Vertex(j));
    n++;
}

void GraphList::insert(char vertex)
{
    if(vertex=='m')
        V.insert(new Vertex(1));
    else V.insert(new Vertex(0));
    n++;
}

void GraphList::insert(int i,int j)
{
    V[i]->edges.insertAsLast(new Edge(i,j));
    e++;
}

ListNode<Edge*>* GraphList::exists(int v, int u) //边(v, u)是否存在
{
    for(ListNode<Edge*>* e=V[v]->edges.first();e->succ!=NULL;e=e->succ)
    {
        if(e->data->j==u) return e;
    }
    return NULL;
}

void GraphList::SPFA(int start)
{
    resetStatus(1);
    Queue<int> queue;
    int s=start;
    V[s]->priority=1-V[s]->data;
    queue.enqueue(start);
    V[s]->status=DISCOVERED;
    while(!queue.empty())
    {
        s=queue.dequeue();
        V[s]->status=UNDISCOVERED;
        int tmp=V[s]->priority;
        for(ListNode<Edge*>* e=firstNbr(s);e->succ!=NULL;e=e->succ)
        {
            int j=e->data->j;
            if(V[j]->priority>tmp+1-V[j]->data)
            {
                V[j]->priority=tmp+1-V[j]->data;
                //V[j]->parent=s;
                if(V[j]->status==UNDISCOVERED)
                {
                    queue.enqueue(j);
                    V[j]->status=DISCOVERED;
                }
            }

        }
    }


}
void GraphList::SPFA_MAX(int start)
{
    resetStatus(0);
    Queue<int> queue;
    int s=start;
    V[s]->priority=V[s]->data;
    queue.enqueue(s);
    V[s]->status=DISCOVERED;
    while(!queue.empty())
    {
        s=queue.dequeue();
        V[s]->status=UNDISCOVERED;
        int tmp=V[s]->priority;
        for(ListNode<Edge*>* e=firstNbr(s);e->succ!=NULL;e=e->succ)
        {
            int j=e->data->j;

            if(V[j]->priority<tmp+V[j]->data)
            {
                V[j]->priority=tmp+V[j]->data;
                if(V[j]->status==UNDISCOVERED)
                {
                    queue.enqueue(j);
                    V[j]->status=DISCOVERED;
                }
            }

        }
    }


}


void GraphList::bcc(GraphList* graph) { //基于DFS的BCC分解算法
   resetStatus(1); int clock = 0; int v =0, s = 0; Stack<int> S; //栈S用以记录已访问的顶点
   int tag=0;

   BCC(v,clock,tag,S,graph);
   for(int i=0;i<n;i++)
   {
       if(V[i]->tag==-1) continue;
       for(ListNode<Edge*>* e=firstNbr(i);e->succ!=NULL;e=e->succ)
       {
           if(V[e->data->j]->tag==-1)continue;
           if(V[i]->tag!=V[e->data->j]->tag)
           graph->insert(V[i]->tag,V[e->data->j]->tag);
       }
   }
}



#define hca(x) (fTime(x)) //利用此处闲置的fTime[]充当hca[]

void GraphList::BCC(int v, int& clock,int& tag, Stack<int>& S, GraphList *graph) {
    hca(v) = dTime(v) = ++clock; status(v) = DISCOVERED; S.push(v);V[v]->inStack=true;
   for (ListNode<Edge*>* u = firstNbr(v); u->succ!=NULL; u=u->succ) //枚举v的所有邻居u
    {
       int j=u->data->j;
       switch (status(j)) { //并视u的状态分别处理
         case UNDISCOVERED:
          // parent(j)=v;
           BCC(j, clock,tag, S,graph);
           hca(v) = min(hca(v), hca(j));
           break;
         default:
           if(V[j]->inStack)
           {

               hca(v)=min(hca(v),dTime(j));
           }

            break;
      }
   }
   if(hca(v)==dTime(v))
   {
       int tmp=0;
       int sum=0;
       do            //依次弹出当前BCC中的节点
       {
             tmp=S.pop();
             sum+=V[tmp]->data;
             V[tmp]->tag=tag;
             V[tmp]->inStack=false;
       }while (v != tmp);
       tag++;
       graph->insert(sum);
   }
   status(v) = VISITED; //对v的访问结束
}
#undef hca


#endif // GRAPHLIST_IMPLEMENTATION_H
