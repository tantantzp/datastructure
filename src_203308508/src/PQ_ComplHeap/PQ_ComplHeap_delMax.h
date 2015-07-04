/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_ComplHeap<T>::delMax() { //删除非空完全二叉堆中优先级最高的词条
   T maxElem = (*heap)[0]; //备份堆顶——按约定，此即优先级最高的词条
   (*heap)[0] = heap->remove(size()-1); //将末词条转移至堆顶
   percolateDown(heap, size(), 0); //对新堆顶实施下滤调整
   return maxElem; //返回此前备份的最大词条
}