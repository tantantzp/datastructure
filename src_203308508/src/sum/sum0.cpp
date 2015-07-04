/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

int sumI(int A[], int n) { //��������㷨�������棩
   int sum = 0; //��ʼ���ۼ�����O(1)
   for (int i = 0; i < n; i++) //��ȫ����O(n)��Ԫ�أ���һ
      sum += A[i]; //�ۼƣ�O(1)
   return sum; //�����ۼ�ֵ��O(1)
} //O(1) + O(n)*O(1) + O(1) = O(n+2) = O(n)