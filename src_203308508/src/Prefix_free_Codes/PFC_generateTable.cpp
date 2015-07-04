/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

void generateCT //ͨ��������ȡ���ַ��ı���
(Bitmap* code, int length, PFCTable* table, BinNodePosi(char) v) {
   if (IsLeaf(*v)) //����Ҷ�ڵ�
      { table->put(v->data, code->bits2string(length)); return; }
   if (HasLChild(*v)) //Left = 0
      { code->clear(length); generateCT(code, length+1, table, v->lChild); }
   if (HasRChild(*v)) //right = 1
      { code->set(length); generateCT(code, length+1, table, v->rChild); }
}

PFCTable* generateTable(PFCTree* tree) { //����PFC�����
   PFCTable* table = new PFCTable; //������Skiplistʵ�ֵı����
   Bitmap* code = new Bitmap; //���ڼ�¼RPS��λͼ
   generateCT(code, 0, table, tree->root()); //�����Ի�ȡ���ַ���Ҷ�ڵ㣩��RPS
   release(code); return table; //�ͷű���λͼ�����ر����
}