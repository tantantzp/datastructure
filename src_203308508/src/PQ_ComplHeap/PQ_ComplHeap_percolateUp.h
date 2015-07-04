/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

// 完全二叉堆词条上滤算法：在向量*A中，对第i个词条实施上滤操作
template <typename T> static Rank percolateUp(Vector<T>* A, Rank i) { //assert: i < A->size()
   while (ParentValid(i)) {
      Rank j = Parent(i); //j为i之父
      if (lt(Node(*A, i), Node(*A, j))) break; //一旦当前父子不再逆序，上滤过程旋即完成
      swap(Node(*A, i), Node(*A, j)); i = j; //否则，父子交换位置
   } //while
   return i; //返回上滤最终抵达的位置
}
