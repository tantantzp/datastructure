/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����������������[lo,hi)�ڣ�ȷ��������e�����һ���ڵ����
Rank Vector<T>::search(T const & e, Rank lo, Rank hi) const { //assert: 0 <= lo < hi <= _size
   return (rand() % 2) ? //����50%�ĸ������ʹ��
      binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi); //���ֲ��һ�Fibonacci����
}