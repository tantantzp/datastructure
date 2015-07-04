/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ/PQ.h" //�������ȼ�����ADT
#include "../List/List.h" //�����б�
template <typename T> class PQ_List : public PQ<T> { //�����б�ʵ�ֵ����ȼ�����
/*DSA*/friend class UniPrint; //��ʾ���ʹ�ã����򲻱���������
private:
   List<T>   *list; //��Ÿ�Ԫ�ص��б�
public:
   PQ_List() { list = new List<T>; } //Ĭ�Ϲ��죺�����ڲ��б�
   PQ_List(T* E, int n) //�������죺����������ʽ������һ��Ԫ����֯Ϊ�б�
   {  list = new List<T>; for (int i = 0; i < n; i++) list->insertAsLast((E[i])); }
   ~PQ_List() { release(list); } //���캯�����ͷ��ڲ��б�
   int size() { return list->size(); } //��ѯ��ǰ��ģ
   bool empty() { return list->empty(); } //�ж��Ƿ�ѿ�
   void insert(T e) { list->insertAsLast(e); } //ֱ�ӽ���Ԫ�ز�������ĩβ
   T getMax() { return list->selectMax()->data; } //ȡ�����ȼ���ߵ�Ԫ��
   T delMax() { return list->remove(list->selectMax()); } //ɾ�����ȼ���ߵ�Ԫ��
}; //PQ_List
