/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_ComplHeap<T>::insert(T e) { //������������ȫ�������
   heap->insert(size(), e); //���Ƚ��´����������ڲ�������ĩβ
   percolateUp(heap, size() - 1); //�ٶԸô���ʵʩ���˵���
}
