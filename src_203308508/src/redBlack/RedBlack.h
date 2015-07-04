/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BST/BST.h" //����BSTʵ��RedBlack
template <typename T> class RedBlack : public BST<T> { //RedBlack��ģ����
protected:
   void solveDoubleRed(BinNodePosi(T) x); //˫������
   void solveDoubleBlack(BinNodePosi(T) x); //˫������
   int updateHeight(BinNodePosi(T) x); //���½ڵ�x�ĸ߶�
public:
   BinNodePosi(T) insert(const T & e); //���루��д��
   bool remove(const T & e); //ɾ������д��
// BST::search()������ӿڿ�ֱ������
};

#include "RedBlack_implementation.h"