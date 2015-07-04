/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //向量选择排序
void Vector<T>::selectionSort(Rank lo, Rank hi) { //assert: 0 < lo <= hi <= size
   /*DSA*/printf("\tSELECTIONsort [%3d,%3d)\n", lo, hi);
   while (lo < --hi)
      exchange(selectMax(lo, hi), hi); //将[hi]与[lo, hi]中的最大者交换
}

template <typename T>
Rank Vector<T>::selectMax(Rank lo, Rank hi) { //在[lo, hi]内找出最大者
   Rank max = hi;
   while (lo < hi--) //逆向扫描
      if (_elem[hi] > _elem[max]) //且严格比较
         max = hi; //故能在max有多个时保证后者优先，进而保证selectionSort稳定
   return max;
}

template <typename T>
void Vector<T>::exchange(Rank i, Rank j) { //交换[i]与[j]的数值
   if (i == j) return; //原地交换时，可省去以下三句并直接返回——对于选择排序，此句是否值得？
   T temp = _elem[i]; _elem[i] = _elem[j]; _elem[j] = temp;
}