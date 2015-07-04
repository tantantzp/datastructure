/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_LeftHeap<T>::insert(T e) { //基于合并操作的词条插入算法
   BinNodePosi(T) v = new BinNode<T>(e); //为e创建一个二叉树节点
   heap->root() = merge(heap->root(), v); //通过合并完成新节点的插入
   heap->root()->parent = NULL; //既然此时堆非空，还需相应设置父子链接
   heap->size()++; //更新规模
}