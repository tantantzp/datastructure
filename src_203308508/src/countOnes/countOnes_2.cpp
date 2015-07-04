/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#define POW(c) (1<<(c))
#define MASK(c) (((unsigned long)-1) / (POW(POW(c)) + 1))
     // MASK(0) = 55555555 h = 01010101010101010101010101010101 b
     // MASK(1) = 33333333 h = 00110011001100110011001100110011 b
     // MASK(2) = 0f0f0f0f h = 00001111000011110000111100001111 b
     // MASK(3) = 00ff00ff h = 00000000111111110000000011111111 b
     // MASK(4) = 0000ffff h = 00000000000000001111111111111111 b
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

int countOnes2(unsigned int n) { //统计整数n的二进制展开中数位1的总数
   n = ROUND(n, 0);
   n = ROUND(n, 1);
   n = ROUND(n, 2);
   n = ROUND(n, 3);
   n = ROUND(n, 4);
   return n;
} //32位字长时，O(log_2(32)) = O(5) = O(1)

