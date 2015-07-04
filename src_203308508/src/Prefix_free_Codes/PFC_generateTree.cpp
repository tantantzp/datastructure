/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

PFCTree* generateTree(PFCForest* forest) { //����PFC��
   srand((unsigned int)time(NULL)); //���ｫ���ȡ���ϲ������������������
   while(1 < forest->size()) { //����|forest|-1�κϲ�
      PFCTree* s = new PFCTree; s->insertAsRoot('^'); //���������������Ϊ"^"��
      Rank r1 = rand() % forest->size(); //���ѡȡr1����
      s->attachAsLC(s->root(), (*forest)[r1]); forest->remove(r1); //��Ϊ������������漴�޳�
      Rank r2 = rand() % forest->size(); //���ѡȡr2����
      s->attachAsRC(s->root(), (*forest)[r2]); forest->remove(r2); //��Ϊ������������漴�޳�
      forest->insert(forest->size(), s); //�ϲ����PFC������ֲ��PFCɭ��
      /*DSA*/printf("%c and %c merged\n", s->root()->lChild->data, s->root()->rChild->data);
   }
   return (*forest)[0]; //���ˣ�ɭ�����д�����һ��������ȫ��PFC������
}