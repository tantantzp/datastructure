/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

void decode(HuffTree* tree, Bitmap* code, int n) { //���ݱ������Գ�Ϊn��Bitmap����Huffman����
   BinNodePosi(HuffChar) x = tree->root();
   for (int i = 0; i < n; i++) {
      x = code->test(i) ? x->rChild : x->lChild;
      if (IsLeaf(*x)) {  printf("%c", x->data.ch); x = tree->root();  }
   }
   /*DSA*/if (x != tree->root()) printf("..."); printf("\n");
} //��������룬�ڴ�ֱ�Ӵ�ӡ�����ʵ���пɸ�Ϊ������Ҫ�����ϲ������