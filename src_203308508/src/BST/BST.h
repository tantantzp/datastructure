/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BinTree/BinTree.h" //����BinTree

template <typename T> class BST : public BinTree<T> { //��BinTree����BSTģ����
protected:
   BinNodePosi(T) _hot; //BST::search()�����ʵķǿգ��������գ��Ľڵ�λ��
   BinNodePosi(T) connect34( //���ա�3+4���ṹ����3���ڵ㼰�Ŀ�����
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
   BinNodePosi(T) rotateAt(BinNodePosi(T) x); //��x���丸�ס��游��ͳһ��ת����
public: //��virtual���Σ��Ա���������д
   virtual BinNodePosi(T) & search(const T & e); //����
   virtual BinNodePosi(T) insert(const T & e); //����
   virtual bool remove(const T & e); //ɾ��
};

#include "BST_implementation.h"