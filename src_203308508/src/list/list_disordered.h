/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "listNode.h"
template <typename T> int List<T>::disordered() const { //ͳ����������Ԫ�ضԵ�����
   int n = 0; ListNode<T>* p = first();
   for (int i = 0; i < _size-1; p = p->succ, i++)
      if (p->data > p->succ->data) n++;
   return n;
}