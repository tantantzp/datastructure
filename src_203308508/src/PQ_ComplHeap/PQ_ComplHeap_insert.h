/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_ComplHeap<T>::insert(T e) { //将词条插入完全二叉堆中
   heap->insert(size(), e); //首先将新词条接入于内部向量的末尾
   percolateUp(heap, size() - 1); //再对该词条实施上滤调整
}
