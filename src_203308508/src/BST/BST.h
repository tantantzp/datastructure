/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../BinTree/BinTree.h" //引入BinTree

template <typename T> class BST : public BinTree<T> { //由BinTree派生BST模板类
protected:
   BinNodePosi(T) _hot; //BST::search()最后访问的非空（除非树空）的节点位置
   BinNodePosi(T) connect34( //按照“3+4”结构联接3个节点及四棵子树
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
   BinNodePosi(T) rotateAt(BinNodePosi(T) x); //对x及其父亲、祖父做统一旋转调整
public: //以virtual修饰，以便派生类重写
   virtual BinNodePosi(T) & search(const T & e); //查找
   virtual BinNodePosi(T) insert(const T & e); //插入
   virtual bool remove(const T & e); //删除
};

#include "BST_implementation.h"