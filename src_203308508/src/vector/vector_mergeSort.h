/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //向量归并排序
void Vector<T>::mergeSort(Rank lo, Rank hi) { //0 <= lo < hi <= size
   /*DSA*/printf("\tMERGEsort [%3d, %3d)\n", lo ,hi);
   if (hi - lo < 2) return; //单元素区间自然有序，否则...
   int mi = (lo + hi) >> 1; //以中点为界
   mergeSort(lo, mi); mergeSort(mi, hi); merge(lo, mi, hi); //分别对前、后半段排序，然后归并
}