/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::disordered() const { //������������������Ԫ�ضԵ�����
   int n = 0; //������
   for (int i = 1; i < _size; i++) //��һ���_size-1������Ԫ��
      if (_elem[i-1] > _elem[i]) n++; //���������
   return n; //���������ҽ���n = 0
}
