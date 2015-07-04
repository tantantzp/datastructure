/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //元素类型（T为基本类型，或已重载赋值操作符'='）
void Vector<T>::copyFrom(T const * A, Rank lo, Rank hi) { //基于数组复制的构造
   _elem = new T[_capacity = 2*(hi-lo)]; _size = 0; //分配空间，规模清零
   while (lo < hi) //A[lo, hi)内的元素逐一
      _elem[_size++] = A[lo++]; //复制至_elem[0, hi-lo)
}