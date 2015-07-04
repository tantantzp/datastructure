/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

void decode(PFCTree* tree, Bitmap& code, int n) { //PFC解码算法
   BinNodePosi(char) x = tree->root(); //根据PFC编码树
   for (int i = 0; i < n; i++) { //将编码（二进制位图）
      x = code.test(i) ? x->rChild : x->lChild; //转译为明码并
      if (IsLeaf(*x)) { printf("%c", x->data); x = tree->root(); } //打印输出
   }
   /*DSA*/if (x != tree->root()) printf(" code seems to be incomplete ..."); printf("\n");
}