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
 * ��������
 ******************************************************************************************/
void printChar(char& p)
{ ('\0' == p) ? printf("\\0 ") : printf("%c  ", p); }

/******************************************************************************************
 * ��ʾ���ʽ�����չ
 ******************************************************************************************/
void displayProgress(char* expr, char* pCh, Stack<float>& opndStk, Stack<char>& optrStk, char* rpn) {
   system("cls");

   printf("\n%s$\n", expr); //β�����ɴ�ӡ��'\0'��'$'��ʾ
   for (char* p=expr; p<pCh; p++) printf("-"); printf("^\n\n");

   print(opndStk); printf("\n");
   print(optrStk); printf("\n");

   printf("RPN:\n %s\n\n", rpn); //���RPN

   getchar();
}