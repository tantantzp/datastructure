/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

void reverse(int* A, int lo, int hi) { //Êý×éµ¹ÖÃ£¨¶àµÝ¹é»ùµÝ¹é°æ£©
   if (lo < hi) {
      swap(A[lo], A[hi]); //½»»»A[lo]ºÍA[hi]
      reverse(A, lo+1, hi-1); //µÝ¹éµ¹ÖÃA[lo+1..hi-1]
   } //elseÒþº¬ÁËÁ½ÖÖµÝ¹é»ù
} //O(hi - lo + 1)