/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

PFCForest* initForest() { //PFC����ɭ�ֳ�ʼ��
   PFCForest* forest = new PFCForest; //���ȴ�����ɭ�֣�Ȼ��
   for (int i = 0; i < N_CHAR; i++) { //��ÿһ���ɴ�ӡ�ַ�[0x20, 0x80)
      forest->insert(i, new PFCTree()); //����һ�ö�Ӧ��PFC����������ʼʱ����
      (*forest)[i]->insertAsRoot(0x20+i); //ֻ������Ӧ��һ����Ҷ�������ڵ�
   }
   return forest; //���ذ���N_CHAR������ɭ�֣�����ÿ����������һ���ַ�
}