/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

inline __int64 sqr(__int64 a) { return a * a; }
__int64 power2(int n) { //幂函数2^n算法（优化递归版），n >= 0
   if (0 == n) return 1; //递归基
   return (n & 1) ? sqr(power2(n >> 1)) << 1 : sqr(power2(n >> 1)); //视n的奇偶分别递归
} //O(logn) = O(r)，r为输入指数n的比特位数