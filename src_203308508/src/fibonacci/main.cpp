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

__int64  fibI(int n); //迭代版
__int64  fib(int n); //二分递归版
__int64  fib(int n, __int64& f); //线性递归版

int main(int argc, char* argv[]) { //测试FIB
// 检查参数
   if (2 > argc) { fprintf(stderr, "Usage: %s <rank>\n", argv[0]); return 1; }
   int n = atoi(argv[1]);

// 依次计算Fibonacci数列各项
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
