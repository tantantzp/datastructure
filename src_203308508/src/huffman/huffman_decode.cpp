/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

void decode(HuffTree* tree, Bitmap* code, int n) { //根据编码树对长为n的Bitmap串做Huffman解码
   BinNodePosi(HuffChar) x = tree->root();
   for (int i = 0; i < n; i++) {
      x = code->test(i) ? x->rChild : x->lChild;
      if (IsLeaf(*x)) {  printf("%c", x->data.ch); x = tree->root();  }
   }
   /*DSA*/if (x != tree->root()) printf("..."); printf("\n");
} //解出的明码，在此直接打印输出；实用中可改为根据需要返回上层调用者