/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T, typename VST> //元素类型、操作器
void travIn_R(BinNodePosi(T) x, VST& visit) { //二叉树中序遍历算法（递归版）
   if (!x) return;
   travIn_R(x->lChild, visit);
   visit(x->data);
   travIn_R(x->rChild, visit);
}
