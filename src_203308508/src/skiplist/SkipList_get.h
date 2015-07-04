/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> V* Skiplist<K, V>::get(K k) { //��ת����������㷨
   if (empty()) return NULL;
   ListNode<Quadlist<Entry<K, V>*>*>* qlist = first(); //�Ӷ���Quadlist��
   QuadlistNode<Entry<K, V>*>* p = qlist->data->first(); //�׽ڵ㿪ʼ
   return skipSearch(qlist, p, k) ? &(p->entry->value) : NULL; //���Ҳ�����
} //�ж������ʱ����������