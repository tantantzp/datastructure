/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../queue/queue.h" //引入队列
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travLevel(VST& visit) { //二叉树层次遍历算法
   Queue<BinNodePosi(T)> Q; //辅助队列
   Q.enqueue(this); //根节点入队
   while (!Q.empty()) { //在队列再次变空之前，反复迭代
      BinNodePosi(T) x = Q.dequeue(); visit(x->data); //取出队首节点并访问之
      if (HasLChild(*x)) Q.enqueue(x->lChild); //左孩子入队
      if (HasRChild(*x)) Q.enqueue(x->rChild); //右孩子入队
   }
}