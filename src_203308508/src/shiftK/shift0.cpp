/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../UniPrint/print_int_array.h"
/*DSA*/int shift(int* A, int n, int s, int t); //��A[s]��������tΪ���ѭ�����ƣ�O(3n)

int shift0(int* A, int n, int k) { //�����ؽ�����ѭ������kλ��O(nk)
   if (k < 1) return 0; int mov = 0;
   while (k--) { //������1Ϊ���ѭ�����ƣ�������k��
      mov += shift(A, n, 0, 1);                                       /*DSA*/printf("== move *%3d\n", mov); print(A, n);
   }
   return mov;
}