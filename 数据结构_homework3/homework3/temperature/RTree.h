#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include "cstdlib"
#include "cstdio"

using namespace std;

struct Point        //点类表示观测站
{
    int x;
    int y;
    int temperature;
    Point(int a=0,int b=0,int c=0):x(a),y(b),temperature(c){}
    void set(int a=0,int b=0,int c=0)
    {x=a,y=b,temperature=c;}
};

static Point* points;  //全局变量，储存所有节点，按x升序排序

class y_list        //对应于全局变量points的下标数组，按y升序排序
{
private:
    void y_sort(int lo,int hi);
    int partition_y(int lo,int hi);
    void add();
public:
    int* p;
    int size;
    long long* sum;           //sum[i]表示前i项的温度和
    y_list(int a,int b)       //将points中下标从a到b的一段按y升序排列构成y_list
    {
        size=b-a+1;
        p=new int[size];
        for(int i=a;i<=b;i++)
        {
            p[i-a]=i;
        }
        y_sort(0,size);
        add();               //生成sum数组
    }
    y_list(y_list *a,y_list *b);   //由两端元素归并生成新y_list，用于自底向上构造树
    ~y_list(){delete sum;delete p;}
    long long search(int start,int end, int &num);  //查找y在start-end之间的符合要求的点，数量累计至num中
    int y_search(int y);       //二分查找，返回不大于y的最大值
};


struct Node           //树节点类
{
    Point p;           //p为根据x进行划分的中点
    Node* lnode;       //lnode中的点x均小于p
    Node* rnode;       //rnode中的点x均大于p
    int start,end;      //Node中存储的额范围
    y_list* list;      //存储一个y_list按照y排序
    Node(int a,int b);     //采用递归构造根节点，仅当当前节点为叶节点时返回，采用归并算法自底向上构造y_list
    ~Node()
    {
        delete lnode;
        delete rnode;
        delete list;
    }

    void search(int& x1,int& x2,int& y1,int& y2,long long& result,int& number);//查找算法
};

class RTree        //RTree类
{
public:
    Node* root;          //根节点
    RTree(int start,int end)
    {
        root=new Node(start,end);
    }

    long long search(int& x1,int& y1,int& x2,int& y2); //查找算法
};


#include "RTree_implementation.h"
#endif // KDTREE_H
