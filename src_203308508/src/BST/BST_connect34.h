/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 按照“3+4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
 * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
 * 可用于AVL和RedBlack的局部平衡调整
 ******************************************************************************************/
template <typename T> BinNodePosi(T) BST<T>::connect34(
   BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
   BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3
) {
   //*DSA*/print(a); print(b); print(c); printf("\n");
   a->lChild = T0; if (T0) T0->parent = a;
   a->rChild = T1; if (T1) T1->parent = a; updateHeight(a);
   c->lChild = T2; if (T2) T2->parent = c;
   c->rChild = T3; if (T3) T3->parent = c; updateHeight(c);
   b->lChild = a; a->parent = b;
   b->rChild = c; c->parent = b; updateHeight(b);
   return b; //该子树新的根节点
}