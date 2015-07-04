/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "queen_stack.h"

int N = 0; //���̴�С

void displayRow(Queen& q) { //��ӡ��ǰ�ʺ󣨷�����col�У�������
   printf("%2d: ", q.x);
   int i = 0;
   while (i++ < q.y) printf("[]");
   printf("��");
   while (i++ < N) printf("[]");
   printf("%2d\n", q.y);
}

void displayProgress(Stack<Queen>& S, int nQueen) { //����������ʾ�Ѳ�Ľ�չ
   system("cls");
   N = nQueen; S.traverse(displayRow);
   if (nQueen <= S.size())
      cout  << nSolu << " solution(s) found after " << nCheck << " check(s)\a";
   getchar();
}