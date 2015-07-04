/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //Ԫ�����ͣ�TΪ�������ͣ��������ظ�ֵ������'='��
void Vector<T>::copyFrom(T const * A, Rank lo, Rank hi) { //�������鸴�ƵĹ���
   _elem = new T[_capacity = 2*(hi-lo)]; _size = 0; //����ռ䣬��ģ����
   while (lo < hi) //A[lo, hi)�ڵ�Ԫ����һ
      _elem[_size++] = A[lo++]; //������_elem[0, hi-lo)
}