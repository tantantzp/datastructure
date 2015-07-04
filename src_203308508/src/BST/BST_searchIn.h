/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //在以v为根的（AVL、SPLAY、rbTree等）BST子树中查找关键码e
static BinNodePosi(T) & searchIn (BinNodePosi(T)& v, const T& e, BinNodePosi(T)& hot) {
   if (!v || (e == v->data)) return v; //至此可确定成功或失败，或者
   hot = v; //先记下当前节点，然后再
   return searchIn(((e < v->data) ? v->lChild : v->rChild), e, hot); //递归查找
} //返回目标节点位置的引用，以便后续插入、删除操作；失败时，返回NULL