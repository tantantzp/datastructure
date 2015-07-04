/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 gcdCN(__int64 a, __int64 b) { //assert: 0 <= min(a, b)
   __int64 r = 1;
   while (true) {
      if (0 == a) return b*r;
      if (0 == b) return a*r;
      if (0 == (a&1) + (b&1)) {
         a >>= 1; b >>= 1; r <<= 1;
      } else if (0 == (a&1))
         a >>= 1;
      else if (0 == (b&1))
         b >>= 1;
      else if (a > b)
         a = a - b;
      else
         b = b - a;
   }
   return 1;
}