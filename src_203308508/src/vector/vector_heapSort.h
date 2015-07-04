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
   T* A = _elem + lo; int n = hi - lo; //��A[0, n) = _elem[lo, hi)
   heapify(A, n); //��֯�ɶѣ�ֻ��O(n)ʱ��
   while (--n > 0) { //��������������ֱ�����˻�Ϊ�����ʼ������������Ԫ��
      swap(A[0], A[n]); //�Ѷ���ĩԪ�ضԻ�
      percolateDown(A, n, 0); //�¡��Ѷ������ˣ��Իָ�������
   }
}