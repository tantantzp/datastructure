/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

//在向量*A的前n个词条中，对第i个词条实施下滤调整
template <typename T> static Rank percolateDown(Vector<T>* A, Rank n, Rank i) { //i < n
   Rank j; //i及其（至多两个）孩子中，堪为父者
   while (i != (j = ProperParent(*A, n, i))) //只要i非j，则
      { swap(Node(*A, i), Node(*A, j)); i = j; } //二者换位，并继续考察下降后的i
   return i; //返回下滤抵达的位置（亦i亦j）
}

//在长度为n数组中，对第i个元素实施下滤调整（可用于Floyd建堆算法）
template <typename T> static Rank percolateDown(T* A, Rank n, Rank i) { //assert: i < n
   //*DSA*/printf("percolating down:"); print(A[i]); printf(" in array of size %d\n", n);
   Rank j; //i及其（至多两个）孩子中，堪为父者
   while (i != (j = ProperParent(A, n, i))) //只要i非j，则
      { swap(Node(A, i), Node(A, j)); i = j; } //二者换位，并继续考察下降后的i
   //*DSA*/for (int k = 0; k < n; k++) print(A[k]); printf("\n");
   return i; //返回下滤抵达的位置（亦i亦j）
}
