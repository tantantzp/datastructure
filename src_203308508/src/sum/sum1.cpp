/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

int sum(int A[], int n) { //��������㷨�����Եݹ�棩
   if (1 > n) //ƽ��������ݹ��
      return 0; //ֱ�ӣ��ǵݹ�ʽ������
   else //һ�����
      return sum(A, n-1) + A[n-1]; //�ݹ飺ǰn-1��֮�ͣ����ۼƵ�n-1��
} //O(1)*�ݹ���� = O(1)*(n+1) = O(n)