#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include "cstdlib"
#include "cstdio"

using namespace std;

struct Point        //�����ʾ�۲�վ
{
    int x;
    int y;
    int temperature;
    Point(int a=0,int b=0,int c=0):x(a),y(b),temperature(c){}
    void set(int a=0,int b=0,int c=0)
    {x=a,y=b,temperature=c;}
};

static Point* points;  //ȫ�ֱ������������нڵ㣬��x��������

class y_list        //��Ӧ��ȫ�ֱ���points���±����飬��y��������
{
private:
    void y_sort(int lo,int hi);
    int partition_y(int lo,int hi);
    void add();
public:
    int* p;
    int size;
    long long* sum;           //sum[i]��ʾǰi����¶Ⱥ�
    y_list(int a,int b)       //��points���±��a��b��һ�ΰ�y�������й���y_list
    {
        size=b-a+1;
        p=new int[size];
        for(int i=a;i<=b;i++)
        {
            p[i-a]=i;
        }
        y_sort(0,size);
        add();               //����sum����
    }
    y_list(y_list *a,y_list *b);   //������Ԫ�ع鲢������y_list�������Ե����Ϲ�����
    ~y_list(){delete sum;delete p;}
    long long search(int start,int end, int &num);  //����y��start-end֮��ķ���Ҫ��ĵ㣬�����ۼ���num��
    int y_search(int y);       //���ֲ��ң����ز�����y�����ֵ
};


struct Node           //���ڵ���
{
    Point p;           //pΪ����x���л��ֵ��е�
    Node* lnode;       //lnode�еĵ�x��С��p
    Node* rnode;       //rnode�еĵ�x������p
    int start,end;      //Node�д洢�ĶΧ
    y_list* list;      //�洢һ��y_list����y����
    Node(int a,int b);     //���õݹ鹹����ڵ㣬������ǰ�ڵ�ΪҶ�ڵ�ʱ���أ����ù鲢�㷨�Ե����Ϲ���y_list
    ~Node()
    {
        delete lnode;
        delete rnode;
        delete list;
    }

    void search(int& x1,int& x2,int& y1,int& y2,long long& result,int& number);//�����㷨
};

class RTree        //RTree��
{
public:
    Node* root;          //���ڵ�
    RTree(int start,int end)
    {
        root=new Node(start,end);
    }

    long long search(int& x1,int& y1,int& x2,int& y2); //�����㷨
};


#include "RTree_implementation.h"
#endif // KDTREE_H
