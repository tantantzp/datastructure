/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::uniquify() { //���������ظ�Ԫ���޳��㷨����Ч�棩
   int oldSize = _size; int i = 0; //��ǰ�ȶ�Ԫ�ص��ȣ���ʼ����Ԫ��
   while (i < _size-1) //��ǰ�����һ�ȶԸ�������Ԫ��
      (_elem[i] == _elem[i + 1]) ? remove(i + 1) : i++; //����ͬ����ɾ�����ߣ�����ת����һԪ��
   return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
}