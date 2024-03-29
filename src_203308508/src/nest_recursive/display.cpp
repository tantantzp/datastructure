/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "../nest_stack/nest.h"

/******************************************************************************************
 * 显示表达式片段exp[lo, hi]，与原表达式对齐
 ******************************************************************************************/
void displaySubstring(const char exp[], int lo, int hi) {
   for (int i = 0; i < lo; i++) printf(" ");
   for (int i = lo; i <= hi; i++) printf("%c", exp[i]);
   printf("\n");
}

/******************************************************************************************
 * 显示表达式扫描进度
 ******************************************************************************************/
void displayProgress(const char exp[], int i, Stack<char> S) {
// 表达式
   system("cls");
   printf("\n%s\n", exp);
   for (int j=0; j<i; j++)   printf("-");
   printf("^\n\n\n");
// 栈
   print(S); getchar();
}
