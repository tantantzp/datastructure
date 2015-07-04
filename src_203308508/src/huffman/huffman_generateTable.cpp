/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

static void //ͨ��������ȡ���ַ��ı���
generateCT(Bitmap* code, int length, HuffTable* table, BinNodePosi(HuffChar) v) {
   if (IsLeaf(*v)) //����Ҷ�ڵ㣨���ж��ַ��������жϣ�
   {  table->put(v->data.ch, code->bits2string(length)); return;  }
   if (HasLChild(*v)) //Left = 0
   { code->clear(length); generateCT(code, length+1, table, v->lChild); }
   if (HasRChild(*v)) //Right = 1
   { code->set(length); generateCT(code, length+1, table, v->rChild); }
}

HuffTable* generateTable(HuffTree* tree) { //�����ַ�����ͳһ������ɢ�б�ʵ�ֵı������
   HuffTable* table = new HuffTable; Bitmap* code = new Bitmap;
   generateCT(code, 0, table, tree->root());
   release(code); return table;
};