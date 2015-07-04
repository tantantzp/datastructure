/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

//������*A��ǰn�������У��Ե�i������ʵʩ���˵���
template <typename T> static Rank percolateDown(Vector<T>* A, Rank n, Rank i) { //i < n
   Rank j; //i���䣨���������������У���Ϊ����
   while (i != (j = ProperParent(*A, n, i))) //ֻҪi��j����
      { swap(Node(*A, i), Node(*A, j)); i = j; } //���߻�λ�������������½����i
   return i; //�������˵ִ��λ�ã���i��j��
}

//�ڳ���Ϊn�����У��Ե�i��Ԫ��ʵʩ���˵�����������Floyd�����㷨��
template <typename T> static Rank percolateDown(T* A, Rank n, Rank i) { //assert: i < n
   //*DSA*/printf("percolating down:"); print(A[i]); printf(" in array of size %d\n", n);
   Rank j; //i���䣨���������������У���Ϊ����
   while (i != (j = ProperParent(A, n, i))) //ֻҪi��j����
      { swap(Node(A, i), Node(A, j)); i = j; } //���߻�λ�������������½����i
   //*DSA*/for (int k = 0; k < n; k++) print(A[k]); printf("\n");
   return i; //�������˵ִ��λ�ã���i��j��
}
