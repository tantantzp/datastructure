/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_ComplHeap<T>::delMax() { //ɾ���ǿ���ȫ����������ȼ���ߵĴ���
   T maxElem = (*heap)[0]; //���ݶѶ�������Լ�����˼����ȼ���ߵĴ���
   (*heap)[0] = heap->remove(size()-1); //��ĩ����ת�����Ѷ�
   percolateDown(heap, size(), 0); //���¶Ѷ�ʵʩ���˵���
   return maxElem; //���ش�ǰ���ݵ�������
}