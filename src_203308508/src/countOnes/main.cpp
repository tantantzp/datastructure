/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "../_share/util.h"
int countOnes(unsigned int n);
int countOnes1(unsigned int n);
int countOnes2(unsigned int n);

void  main(int argc, char* argv[]) { //二进制数位1计数算法测试入口
   for (unsigned int i = 0; i < 512; i++)
      printf("%6d = %4X: %6d %6d %6d\n", i, i, countOnes(i), countOnes1(i), countOnes2(i));
}