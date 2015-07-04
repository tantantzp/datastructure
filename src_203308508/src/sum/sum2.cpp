/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

int sum(int A[], int lo, int hi) { //��������㷨�����ֵݹ�棬���Ϊsum(A, 0, n-1)��
   if (lo == hi) //�����ݹ�������䳤���ѽ���1������
      return A[lo]; //ֱ�ӷ��ظ�Ԫ��
   else { //����һ�������lo < hi������
      int mi = (lo + hi) >> 1; //�Ծ��е�ԪΪ�磬��ԭ����һ��Ϊ��
      return sum(A, lo, mi) + sum(A, mi+1, hi); //�ݹ�Ը���������ͣ�Ȼ��ϼ�
   }
} //O(hi-lo+1)����������������ĳ���