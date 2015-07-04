/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> static T* heapify(T* A, Rank n) { //Floyd�����㷨��O(n)ʱ��
    for (int i = LastInternal(n); InHeap(n, i); i--) //�Ե׶��ϣ�����
       percolateDown(A, n, i); //���˸��ڲ��ڵ�
    return A;
}
