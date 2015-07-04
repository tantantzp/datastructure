/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::unsort(Rank lo, Rank hi) { //等概率随机置乱向量区间[lo,hi)
   T* V = _elem + lo; //将子向量_elem[lo, hi)视作另一向量V[0, hi-lo)
   for (Rank i = hi-lo; i > 0; i--) //自后向前
      swap(V[i-1], V[rand() % i]); //将V[i-1]与V[0, i-1]中某一元素随机交换
}