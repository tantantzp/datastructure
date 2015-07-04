/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) { //x->lChild == NULL
   if (x->lChild = S->_root) x->lChild->parent = x; //接入
   _size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度
   S->_root = NULL; S->_size = 0; release(S); S = NULL; //释放原树
   return x; //返回接入位置
}

template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) { //x->rChild == NULL
   if (x->rChild = S->_root) x->rChild->parent = x; //接入
   _size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度
   S->_root = NULL; S->_size = 0; release(S); S = NULL; //释放原树
   return x; //返回接入位置
}