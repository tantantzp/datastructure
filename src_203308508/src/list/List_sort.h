/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::sort(ListNodePosi(T) p, int n) { //�б���������
   switch (rand() % 3) { //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
      case 1:  insertionSort(p, n); break; //��������
      case 2:  selectionSort(p, n); break; //ѡ������
      default: mergeSort(p, n); break; //�鲢����
   }
}