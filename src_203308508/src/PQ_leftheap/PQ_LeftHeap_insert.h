/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_LeftHeap<T>::insert(T e) { //���ںϲ������Ĵ��������㷨
   BinNodePosi(T) v = new BinNode<T>(e); //Ϊe����һ���������ڵ�
   heap->root() = merge(heap->root(), v); //ͨ���ϲ�����½ڵ�Ĳ���
   heap->root()->parent = NULL; //��Ȼ��ʱ�ѷǿգ�������Ӧ���ø�������
   heap->size()++; //���¹�ģ
}