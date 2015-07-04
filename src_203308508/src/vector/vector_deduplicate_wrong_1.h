/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

template <typename T> int Vector<T>::deduplicate() { //ɾ�������������ظ�Ԫ�أ�����棩
   int oldSize = _size; //��¼ԭ��ģ
   for (Rank i = 1; i < _size; i++) {
      Rank j = find(_elem[i], 0, i); //��_elem[i]��ǰ����Ѱ����֮��ͬ�ߣ�����һ����
      if (0 <= j) remove(j); //�����ڣ���ɾ��֮��ͬʱ����--iʹ��ǰԪ��ǰ�ƣ�
   }
   return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
}