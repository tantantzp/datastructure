/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����ѡ������
void Vector<T>::selectionSort(Rank lo, Rank hi) { //assert: 0 < lo <= hi <= size
   /*DSA*/printf("\tSELECTIONsort [%3d,%3d)\n", lo, hi);
   while (lo < --hi)
      exchange(selectMax(lo, hi), hi); //��[hi]��[lo, hi]�е�����߽���
}

template <typename T>
Rank Vector<T>::selectMax(Rank lo, Rank hi) { //��[lo, hi]���ҳ������
   Rank max = hi;
   while (lo < hi--) //����ɨ��
      if (_elem[hi] > _elem[max]) //���ϸ�Ƚ�
         max = hi; //������max�ж��ʱ��֤�������ȣ�������֤selectionSort�ȶ�
   return max;
}

template <typename T>
void Vector<T>::exchange(Rank i, Rank j) { //����[i]��[j]����ֵ
   if (i == j) return; //ԭ�ؽ���ʱ����ʡȥ�������䲢ֱ�ӷ��ء�������ѡ�����򣬴˾��Ƿ�ֵ�ã�
   T temp = _elem[i]; _elem[i] = _elem[j]; _elem[j] = temp;
}