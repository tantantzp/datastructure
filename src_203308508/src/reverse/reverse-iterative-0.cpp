/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void reverse(int* A, int lo, int hi) { //���鵹�ã�ֱ�Ӹ�����õĵ����棩
next: //�㷨��ʼλ�������ת��־
   if (lo < hi) {
      swap(A[lo], A[hi]); //����A[lo]��A[hi]
      lo++; hi--; //��������������
      goto next; //��ת���㷨�����ʼλ�ã������ص���A[lo+1, hi-1]
   } //else�����˵�������ֹ
} //O(hi - lo + 1)