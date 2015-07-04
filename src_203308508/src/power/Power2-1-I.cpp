/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 power2_I(int n) { //幂函数2^n算法（优化迭代版），n >= 0
   __int64 pow = 1; //O(1)：累积器初始化为2^0
   __int64 p = 2; //O(1)：累乘项初始化为2
   while (0 < n) { //O(logn)：迭代log(n)轮，每轮都
      if (n & 1) //O(1)：根据当前比特位是否为1，决定是否
         pow *= p; //O(1)：将当前累乘项计入累积器
      n >>= 1; //O(1)：指数减半
      p *= p; //O(1)：累乘项自乘
   }
   return pow; //O(1)：返回累积器
} //O(logn) = O(r)，r为输入指数n的比特位数