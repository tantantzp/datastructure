#include <iostream>
#include "cstdlib"
#include "stdio.h"
#include "ctime"
#include "temperature.h"
#include "RTree.h"

using namespace std;

void x_sort(Point* p,int lo, int hi);
int partition_x(Point* p,int lo,int hi);

int main()
{
    srand((unsigned)time(NULL));
    int N;
    N=GetNumOfStation();
    int x,y,t;
    points=new Point[N];          //Point数组存储节点
    for(int i=0;i<N;i++)
    {
        GetStationInfo(i,&x,&y,&t);
        points[i].set(x,y,t);
    }
    x_sort(points,0,N);
    RTree* tree=new RTree(0,N-1);    //创建RTree
    int x1,y1,x2,y2;
    int a=1000;
    while(GetQuery(&x1,&y1,&x2,&y2))
    {
        int a=tree->search(x1,y1,x2,y2);    //调用查询接口
        Response(a);
    }
    return 0;
}


void x_sort(Point* p,int lo, int hi) {        //将point数组按x顺序排序，采用快排算法
   if (hi-lo < 2) return;
   int mi = partition_x(p,lo, hi-1);
   x_sort(p,lo, mi);
   x_sort(p,mi+1, hi);
}

int partition_x(Point* p,int lo,int hi) {
   swap(p[lo], p[lo + rand() % (hi-lo+1)]);
   Point pivot = p[lo];
   while (lo < hi) {
      while ((lo < hi) && (pivot.x <= p[hi].x)) hi--;
      p[lo] = p[hi];
      while ((lo < hi) && (p[lo].x <= pivot.x)) lo++;
      p[hi] = p[lo];
   }
   p[lo] = pivot;
   return lo;
}
