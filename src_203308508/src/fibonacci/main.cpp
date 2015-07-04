/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include<time.h>
#include<iostream>
using namespace std;

__int64  fibI(int n); //������
__int64  fib(int n); //���ֵݹ��
__int64  fib(int n, __int64& f); //���Եݹ��

int main(int argc, char* argv[]) { //����FIB
// ������
   if (2 > argc) { fprintf(stderr, "Usage: %s <rank>\n", argv[0]); return 1; }
   int n = atoi(argv[1]);

// ���μ���Fibonacci���и���
   printf("\n------------- Iteration -------------\n");
   for (int i = 0; i < n; i++)
      printf("fib(%2d) = %22I64d\n", i, fibI(i));

   printf("\n------------- Linear Recursion -------------\n");
   for (int i = 0; i < n; i++) {
      __int64 f;
      printf("fib(%2d) = %22I64d\n", i, fib(i, f));
   }

   printf("\n------------- Binary Recursion -------------\n");
   for (int i = 0; i < n; i++)
      printf("fib(%2d) = %22I64d\n", i, fib(i));

   return 0;
}
