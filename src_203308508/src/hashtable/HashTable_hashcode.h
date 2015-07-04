/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

// 散列码转换函数：将任意类型K的关键词转换为（尽可能互异的）整数
static size_t hashCode(char s[]) {
   int h = 0;
   for (size_t n = strlen(s), i = 0; i < n; i++)
      { h = (h << 5) | (h >> 27); h += (int) s[i]; }
   return (size_t) h;
}
static size_t hashCode(int k) { return (size_t) k; }
static size_t hashCode(char c) { return (size_t) c; }
static size_t hashCode(long long i) { return (size_t) ((i >> 32) + (int) i); }
