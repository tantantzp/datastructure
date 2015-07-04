/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T, typename VST> //元素类型、操作器
void travIn_I4(BinNodePosi(T) x, VST& visit) { //二叉树中序遍历算法（迭代版#4，无需栈或标志位）
   while (true)
      if (HasLChild(*x)) //若有左子树，则
         x = x->lChild; //深入遍历左子树
      else { //否则
         visit(x->data); //访问当前节点，并
         while (!HasRChild(*x)) { //反复
            if (!(x = x->succ())) return; //回溯
            visit(x->data); //访问当前节点
         }
         x = x->rChild; //转向非空的右子树
      }
}