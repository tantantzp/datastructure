/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::heapSort(Rank lo, Rank hi) { //0 <= lo < hi <= size
   /*DSA*/printf("\tHEAPsort [%3d,%3d)\n", lo, hi);
   T* A = _elem + lo; int n = hi - lo; //将A[0, n) = _elem[lo, hi)
   heapify(A, n); //组织成堆，只需O(n)时间
   while (--n > 0) { //堆区间逐步收缩，直至堆退化为（或初始即）不足两个元素
      swap(A[0], A[n]); //堆顶与末元素对换
      percolateDown(A, n, 0); //新“堆顶”下滤，以恢复堆序性
   }
}