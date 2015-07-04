/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::clear() { //����б�
   int oldSize = _size;
   while (0 < _size) remove(header->succ); //����ɾ���׽ڵ㣬ֱ���б���
   return oldSize;
}