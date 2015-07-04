/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //引入优先级队列ADT
#include "../BinTree/BinTree.h" //引入二叉树节点模板类
template <typename T> class PQ_LeftHeap : public PQ<T> { //以左式堆形式实现的优先级队列
/*DSA*/friend class UniPrint; //演示输出使用，否则不必设置友类
private:
   BinTree<T>* heap; //各元素在内部组织为二叉树
public:
   PQ_LeftHeap() { heap = new BinTree<T>; } //默认构造：创建内部二叉树
   PQ_LeftHeap(T* E, int n) //可改进为Floyd建堆算法
   {  heap = new BinTree<T>; for (int i = 0; i < n; i++) insert(E[i]);  }
   ~PQ_LeftHeap() { release(heap); } //构造函数：释放内部二叉树
   int size() { return heap->size(); } //查询当前规模
   bool empty() { return heap->empty(); } //判断是否堆空
   void insert(T); //按照比较器确定的优先级次序插入元素
   T getMax(); //取出优先级最高的元素
   T delMax(); //删除优先级最高的元素
}; //PQ_LeftHeap

#include "PQ_LeftHeap_implementation.h"