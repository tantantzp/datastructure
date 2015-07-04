/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 fibI(int n) { //计算Fibonacci数列的第n项（迭代版）：O(n)
   __int64 f = 1, g = 0; //初始化：fib(1)=1, fib(0)=0
   while (0 < n--) { f = f + g; g = f - g; } //依据原始定义，通过n次加法和减法计算fib(n)
   return g; //返回
}