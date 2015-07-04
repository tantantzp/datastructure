/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const & V ) { //���ظ�ֵ������
   if (_elem) delete [] _elem; //�ͷ�ԭ������
   copyFrom(V._elem, 0, V.size()); //���帴��
   return *this; //���ص�ǰ��������ã��Ա���ʽ��ֵ
}