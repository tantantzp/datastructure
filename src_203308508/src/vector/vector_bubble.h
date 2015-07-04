/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi) { //һ��ɨ�轻��
   bool sorted = true; //���������־
   while (++lo < hi) //�������ң���һ����������Ԫ��
      if (_elem[lo-1] > _elem[lo]) { //��������
         sorted = false; //��ζ����δ�������򣬲���Ҫ
         swap(_elem[lo-1], _elem[lo]); //ͨ������ʹ�ֲ�����
      }
   return sorted; //���������־
}