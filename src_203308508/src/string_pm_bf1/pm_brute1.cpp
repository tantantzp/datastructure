/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include <stdio.h>
#include <string.h>
/*DSA*/void showProgress(char*, char*, int, int);

/******************************************************************************************
 * Text     :  0   1   2   .   .   .   i-j .   .   .   .   i   .   .   n-1
 *             ------------------------|-------------------|------------
 * Pattern  :                          0   .   .   .   .   j   .   .
 *                                     |-------------------|
 ******************************************************************************************/
int match(char* P, char* T) { //串匹配算法（Brute-force-1）
   size_t n = strlen(T), i = 0; //主串长度、当前接受比对字符的位置
   size_t m = strlen(P), j = 0; //模式串长度、当前接受比对字符的位置
   while (j < m && i < n) //自左向右逐个比对字符
      /*DSA*/{
      /*DSA*/showProgress(T, P, i - j, j);   getchar();
      if (T[i] == P[j]) //若匹配
         { i ++;  j ++; } //则转到下一对字符
      else //否则
         { i -= j - 1; j = 0; } //主串回退、模式串复位
      /*DSA*/}
   return i - j; //如何通过返回值，判断匹配结果？
}
