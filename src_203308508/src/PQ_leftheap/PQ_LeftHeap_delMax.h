/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::delMax() { //���ںϲ������Ĵ���ɾ���㷨����ǰ���зǿգ�
   BinNodePosi(T) lHeap = heap->root()->lChild; //���Ӷ�
   BinNodePosi(T) rHeap = heap->root()->rChild; //���Ӷ�
   T e = heap->root()->data; delete heap->root(); heap->size()--; //ɾ�����ڵ�
   heap->root() = merge(lHeap, rHeap); //ԭ�����ӶѺϲ�
   if (heap->root()) heap->root()->parent = NULL; //���ѷǿգ�������Ӧ���ø�������
   return e; //����ԭ���ڵ��������
}