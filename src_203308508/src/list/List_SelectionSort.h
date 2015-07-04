/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�б���ѡ�������㷨������ʼ��λ��p��n��Ԫ������
void List<T>::selectionSort(ListNodePosi(T) p, int n) { //valid(p) && rank(p) + n <= size
   /*DSA*/printf("SelectionSort ...\n");
   ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
   for (int i = 0; i < n; i++) tail = tail->succ; //����������Ϊ(head, tail)
   while (1 < n) { //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
      ListNodePosi(T) max = selectMax(head->succ, n); //�ҳ�����ߣ�����ʱ�������ȣ�
      insertBefore(tail, remove(max)); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
      tail = tail->pred; n--;
   }
}