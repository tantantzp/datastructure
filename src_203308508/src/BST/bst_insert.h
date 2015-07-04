/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BST<T>::insert(const T& e) { //将关键码e插入BST树中
   BinNodePosi(T) & x = search(e); if (x) return x; //确认目标节点不存在（留意对_hot的设置）
   x = new BinNode<T>(e, _hot); //创建新节点x：以e为关键码，以_hot为父
   _size++; //更新全树规模
   updateHeightAbove(x); //更新x及其历代祖先的高度
   return x;
} //无论e是否存在于原树中，返回时总有x->data == e
