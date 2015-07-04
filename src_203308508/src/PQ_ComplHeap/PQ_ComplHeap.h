/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //�������ȼ�����ADT
#include "../Vector/Vector.h" //��������
template <typename T> class PQ_ComplHeap : public PQ<T> { //��������������ȫ�������ʽʵ�ֵ�PQ
/*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
private:
   Vector<T>* heap; //��Ÿ�����������
public:
   PQ_ComplHeap() { heap = new Vector<T>; } //Ĭ�Ϲ��죺�����ڲ�����
   PQ_ComplHeap(T* E, int n) //�������죺����������ʽ������һ�������֯Ϊ��ȫ��
   {  heap = new Vector<T>(heapify(E, n), n);  }
   ~PQ_ComplHeap() { release(heap); } //���캯�����ͷ��ڲ�����
   int size() { return heap->size(); } //��ѯ��ǰ��ģ
   bool empty() { return heap->empty(); } //�ж��Ƿ�ѿ�
   void insert(T); //���ձȽ���ȷ�������ȼ�����������
   T getMax(); //ȡ�����ȼ���ߵĴ���
   T delMax(); //ɾ�����ȼ���ߵĴ���
}; //PQ_ComplHeap
/*DSA*/#include "PQ_ComplHeap_macro.h"


#include "PQ_ComplHeap_implementation.h"