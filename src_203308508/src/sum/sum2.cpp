/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

int sum(int A[], int lo, int hi) { //数组求和算法（二分递归版，入口为sum(A, 0, n-1)）
   if (lo == hi) //如遇递归基（区间长度已降至1），则
      return A[lo]; //直接返回该元素
   else { //否则（一般情况下lo < hi），则
      int mi = (lo + hi) >> 1; //以居中单元为界，将原区间一分为二
      return sum(A, lo, mi) + sum(A, mi+1, hi); //递归对各子数组求和，然后合计
   }
} //O(hi-lo+1)，线性正比于区间的长度