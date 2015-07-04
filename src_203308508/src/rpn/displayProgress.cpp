/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "rpn.h"
#include "../UniPrint/print.h"

/******************************************************************************************
 * 输出运算符
 ******************************************************************************************/
void printChar(char& p)
{ ('\0' == p) ? printf("\\0 ") : printf("%c  ", p); }

/******************************************************************************************
 * 显示表达式处理进展
 ******************************************************************************************/
void displayProgress(char* expr, char* pCh, Stack<float>& opndStk, Stack<char>& optrStk, char* rpn) {
   system("cls");

   printf("\n%s$\n", expr); //尾部不可打印的'\0'用'$'表示
   for (char* p=expr; p<pCh; p++) printf("-"); printf("^\n\n");

   print(opndStk); printf("\n");
   print(optrStk); printf("\n");

   printf("RPN:\n %s\n\n", rpn); //输出RPN

   getchar();
}