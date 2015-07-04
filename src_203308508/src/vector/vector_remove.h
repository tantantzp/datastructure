/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T Vector<T>::remove(Rank r) { //ɾ����������Ϊr��Ԫ�أ�0 <= r < size
   T e = _elem[r]; //���ݱ�ɾ��Ԫ��
   remove(r, r + 1); //��������ɾ���㷨����Ч�ڶ�����[r, r + 1)��ɾ��
   return e; //���ر�ɾ��Ԫ��
}