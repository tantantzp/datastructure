/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 powerBF(__int64 a, int n) { //a^nËã·¨£¨ÂùÁ¦°æ£©£ºn >= 0
   __int64 pow = 1; //O(1)
   while (0 < n) { //O(n)
      pow *= a; //O(1)
      n--; //O(1)
   }
   return pow; //O(1)
} //powerBF()