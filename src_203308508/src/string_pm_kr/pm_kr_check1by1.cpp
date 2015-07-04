/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "pm_kr.h"

bool check1by1(char* P, char* T, size_t i) { //指纹相同（概率很小）时，逐位比对以确认是否真正匹配
   for (size_t m = strlen(P), j = 0; j < m; j++, i++)
      if (P[j] != T[i]) return false;
   return true;
}
