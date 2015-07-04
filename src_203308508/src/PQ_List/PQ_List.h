/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //引入优先级队列ADT
#include "../List/List.h" //引入列表
template <typename T> class PQ_List : public PQ<T> { //基于列表实现的优先级队列
/*DSA*/friend class UniPrint; //演示输出使用，否则不必设置友类
private:
   List<T>   *list; //存放各元素的列表
public:
   PQ_List() { list = new List<T>; } //默认构造：创建内部列表
   PQ_List(T* E, int n) //批量构造：将以数组形式给出的一组元素组织为列表
   {  list = new List<T>; for (int i = 0; i < n; i++) list->insertAsLast((E[i])); }
   ~PQ_List() { release(list); } //构造函数：释放内部列表
   int size() { return list->size(); } //查询当前规模
   bool empty() { return list->empty(); } //判断是否堆空
   void insert(T e) { list->insertAsLast(e); } //直接将新元素插至队列末尾
   T getMax() { return list->selectMax()->data; } //取出优先级最高的元素
   T delMax() { return list->remove(list->selectMax()); } //删除优先级最高的元素
}; //PQ_List
