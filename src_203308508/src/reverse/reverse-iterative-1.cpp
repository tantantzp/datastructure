/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void reverse(int* A, int lo, int hi) { //���鵹�ã��淶����֮��ĵ����棩
   while (lo < hi) //��while�滻��ת��־��if����ȫ��Ч
      swap(A[lo++], A[hi--]); //����A[lo]��A[hi]����������������
} //O(hi - lo + 1)