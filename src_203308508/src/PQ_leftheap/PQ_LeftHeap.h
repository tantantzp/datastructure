/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //�������ȼ�����ADT
#include "../BinTree/BinTree.h" //����������ڵ�ģ����
template <typename T> class PQ_LeftHeap : public PQ<T> { //����ʽ����ʽʵ�ֵ����ȼ�����
/*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
private:
   BinTree<T>* heap; //��Ԫ�����ڲ���֯Ϊ������
public:
   PQ_LeftHeap() { heap = new BinTree<T>; } //Ĭ�Ϲ��죺�����ڲ�������
   PQ_LeftHeap(T* E, int n) //�ɸĽ�ΪFloyd�����㷨
   {  heap = new BinTree<T>; for (int i = 0; i < n; i++) insert(E[i]);  }
   ~PQ_LeftHeap() { release(heap); } //���캯�����ͷ��ڲ�������
   int size() { return heap->size(); } //��ѯ��ǰ��ģ
   bool empty() { return heap->empty(); } //�ж��Ƿ�ѿ�
   void insert(T); //���ձȽ���ȷ�������ȼ��������Ԫ��
   T getMax(); //ȡ�����ȼ���ߵ�Ԫ��
   T delMax(); //ɾ�����ȼ���ߵ�Ԫ��
}; //PQ_LeftHeap

#include "PQ_LeftHeap_implementation.h"