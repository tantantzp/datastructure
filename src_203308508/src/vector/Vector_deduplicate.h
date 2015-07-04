/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::deduplicate() { //ɾ�������������ظ�Ԫ�أ���Ч�棩
   int oldSize = _size; //��¼ԭ��ģ
   Rank i = 1; //��_elem[1]��ʼ
   while (i < _size) //��ǰ�����һ�����Ԫ��_elem[i]
      (find(_elem[i], 0, i) < 0) ? //����ǰ׺��Ѱ����֮��ͬ�ߣ�����һ����
         i++ : remove(i); //������ͬ������������̣�����ɾ����ͬ��
   return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
}