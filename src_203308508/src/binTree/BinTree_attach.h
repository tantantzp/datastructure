/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //���������������㷨����S�����ڵ�x�����������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) { //x->lChild == NULL
   if (x->lChild = S->_root) x->lChild->parent = x; //����
   _size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶�
   S->_root = NULL; S->_size = 0; release(S); S = NULL; //�ͷ�ԭ��
   return x; //���ؽ���λ��
}

template <typename T> //���������������㷨����S�����ڵ�x�����������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) { //x->rChild == NULL
   if (x->rChild = S->_root) x->rChild->parent = x; //����
   _size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶�
   S->_root = NULL; S->_size = 0; release(S); S = NULL; //�ͷ�ԭ��
   return x; //���ؽ���λ��
}