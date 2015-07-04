/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 facR(int n) { return (n < 1) ? 1 : n*facR(n-1); } //½×³ËÔËËã£¨µÝ¹é°æ£©