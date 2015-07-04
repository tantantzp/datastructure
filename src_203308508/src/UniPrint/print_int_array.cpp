/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include <stdio.h>

void print(int A[], int n, int lo, int hi) { //���������������A[lo, hi)
   bool sorted = true;
   for (int i = 1; i < n; i++) if (A[i-1] > A[i]) sorted = false;
   printf(sorted ? "S: " : " : ");
   for (int i = 0; i < lo; i++) printf("   .");
   for (int i = lo; i < hi; i++) printf("%4d", A[i]);
   for (int i = hi; i < n; i++) printf("   .");
   printf("\n");
}

void print(int A[], int n) { print(A, n, 0, n); }
