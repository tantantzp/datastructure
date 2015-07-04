/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //������������
void Vector<T>::quickSort(Rank lo, Rank hi) { //0 <= lo < hi <= size
   /*DSA*/printf("\tQUICKsort [%3d,%3d)\n", lo, hi);
   if (hi-lo < 2) return; //��Ԫ��������Ȼ���򣬷���...
   Rank mi = partition(lo, hi-1); //��[lo, hi-1]�ڹ������
   quickSort(lo, mi); //��ǰ׺�ݹ�����
   quickSort(mi+1, hi); //�Ժ�׺�ݹ�����
}