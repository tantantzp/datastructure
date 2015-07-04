/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

template <typename T> int Vector<T>::deduplicate() { //删除无序向量中重复元素（错误版）
   int oldSize = _size; //记录原规模
   for (Rank i = 1; i < _size; i++) {
      Rank j = find(_elem[i], 0, i); //在_elem[i]的前驱中寻找与之雷同者（至多一个）
      if (0 <= j) remove(j); //若存在，则删除之（同时须令--i使当前元素前移）
   }
   return oldSize - _size; //向量规模变化量，即被删除元素总数
}