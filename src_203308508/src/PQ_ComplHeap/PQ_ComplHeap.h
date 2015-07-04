/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //引入优先级队列ADT
#include "../Vector/Vector.h" //引入向量
template <typename T> class PQ_ComplHeap : public PQ<T> { //基于向量，以完全二叉堆形式实现的PQ
/*DSA*/friend class UniPrint; //演示输出使用，否则不必设置友类
private:
   Vector<T>* heap; //存放各词条的向量
public:
   PQ_ComplHeap() { heap = new Vector<T>; } //默认构造：创建内部向量
   PQ_ComplHeap(T* E, int n) //批量构造：将以数组形式给出的一组词条组织为完全堆
   {  heap = new Vector<T>(heapify(E, n), n);  }
   ~PQ_ComplHeap() { release(heap); } //构造函数：释放内部向量
   int size() { return heap->size(); } //查询当前规模
   bool empty() { return heap->empty(); } //判断是否堆空
   void insert(T); //按照比较器确定的优先级次序插入词条
   T getMax(); //取出优先级最高的词条
   T delMax(); //删除优先级最高的词条
}; //PQ_ComplHeap
/*DSA*/#include "PQ_ComplHeap_macro.h"


#include "PQ_ComplHeap_implementation.h"