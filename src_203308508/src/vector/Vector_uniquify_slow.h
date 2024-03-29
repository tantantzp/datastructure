/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::uniquify() { //有序向量重复元素剔除算法（低效版）
   int oldSize = _size; int i = 0; //当前比对元素的秩，起始于首元素
   while (i < _size-1) //从前向后，逐一比对各对相邻元素
      (_elem[i] == _elem[i + 1]) ? remove(i + 1) : i++; //若雷同，则删除后者；否则，转至后一元素
   return oldSize - _size; //向量规模变化量，即被删除元素总数
}