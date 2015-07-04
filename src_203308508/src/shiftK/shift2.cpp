/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../reverse/reverse.h"
/*DSA*/#include "../UniPrint/print_int_array.h"

int shift2(int* A, int n, int k) { //借助倒置算法，将数组循环左移k位，O(3n)
   reverse(A, k);       /* O(3k/2) */                                      /*DSA*/print(A, n, 0, k);
   reverse(A+k, n-k);   /* O(3(n-k)/2) */                                  /*DSA*/print(A, n, k, n);
   reverse(A, n);       /* O(3n/2) */                                      /*DSA*/print(A, n);
   return 3*n;          /* 3/2 * (k + (n-k) + n) */
}