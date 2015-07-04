/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST节点删除算法：删除位置v所指的节点（全局静态模板函数，适用于AVL、Splay、RedBlack等各种BST）
 * v通常由此前的查找确定，经确认非NULL后方调用本函数，故必删除成功
 * 与searchIn不同，调用之前不必将hot置空
 * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲——二者均有可能是NULL
 ******************************************************************************************/
template <typename T> static BinNodePosi(T) removeAt(BinNodePosi(T)& v, BinNodePosi(T)& hot) {
   BinNodePosi(T) w = v; //实际被摘除的节点，初值同v
   BinNodePosi(T) succ = NULL; //实际被删除节点的接替者
   if (!HasLChild(*v)) //若*v的左子树为空，则可
      succ = v = v->rChild; //直接将*v替换为其右子树
   else if (!HasRChild(*v)) //若右子树为空，则可
      succ = v = v->lChild; //对称地处理——注意：此时succ != NULL
   else { //若左右子树均存在，则选择v的直接后继作为实际被摘除节点，为此需要
      w = w->succ(); //（在右子树中）找到*v的直接后继*w
      swap(v->data, w->data); //交换*v和*w的数据元素
      BinNodePosi(T) u = w->parent;
      ((u == v) ? u->rChild : u->lChild) = succ = w->rChild; //隔离节点*w
   }
   hot = w->parent; //记录实际被删除节点的父亲
   if (succ) succ->parent = hot; //并将被删除节点的接替者与hot相联
   release(w->data); release(w); //释放被摘除节点
   return succ; //返回接替者
}
