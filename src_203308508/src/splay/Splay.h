/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BST/BST.h" //����BSTʵ��Splay
template <typename T> class Splay : public BST<T> { //��BST������Splay��ģ����
protected:
   BinNodePosi(T) splay(BinNodePosi(T) v); //���ڵ�v��չ����
public:
   BinNodePosi(T) & search(const T & e); //���ң���д��
   BinNodePosi(T) insert(const T & e); //���루��д��
   bool remove(const T & e); //ɾ������д��
};

#include "Splay_implementation.h"