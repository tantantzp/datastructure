/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) RedBlack<T>::insert(const T& e) { //将关键码e插入红黑树
   BinNodePosi(T) & x = search(e); if (x) return x; //确认目标节点不存在（留意对_hot的设置）
   x = new BinNode<T>(e, _hot, NULL, NULL, -1); _size++; //创建红节点x：以_hot为父，黑高度-1
   solveDoubleRed(x); return x; //经双红修正后，即可返回
} //无论e是否存在于原树中，返回时总有x->data == e
