#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

void del(List<char>& nodes,ListNode<char>* p);


int main()
{

    char nodes[10000];
    int n;
    cin>>nodes>>n;
    List<char> a(nodes);
    //a.output();
    int r;
    char tmp;
    for(int i=0;i<n;i++)
    {
        cin>>r>>tmp;
        del(a,a.insertAt(r,tmp));
        a.output();
    }

    return 0;
}



void del(List<char>& nodes,ListNode<char>* p)        //�ݹ�Ľ���������� 
{
    int num=1;
    ListNode<char>* tmp=p->pred;
    while((tmp->pred!=NULL)&&(tmp->data==p->data))    //tmp��¼p֮ǰ��pͬɫ����ǰһ������ 
    {
        num++;
        tmp=tmp->pred;
    }
    tmp=tmp->succ;
    ListNode<char>* tmp2=p->succ;
    while((tmp2->succ!=NULL)&&(tmp2->data==p->data))  //tmp2��¼p֮����pͬɫ�����һ������ 
    {
        num++;
        tmp2=tmp2->succ;
    }
    tmp2=tmp2->pred;
    ListNode<char>* tmp3;
    if((tmp->pred->pred)){tmp3=tmp->pred;}            //����tmpΪ�׽ڵ����� 
    else tmp3=tmp2->succ;
    if(num>=3)
    {
        nodes.remove(tmp,tmp2);
        if(tmp3->pred && tmp3->succ)  del(nodes,tmp3);
    }
    else return;


}

