/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> static T* heapify(T* A, Rank n) { //Floyd建堆算法，O(n)时间
    for (int i = LastInternal(n); InHeap(n, i); i--) //自底而上，依次
       percolateDown(A, n, i); //下滤各内部节点
    return A;
}
