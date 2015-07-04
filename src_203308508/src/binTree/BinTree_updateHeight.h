/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) //更新节点x高度
{ return x->height = 1 + max(stature(x->lChild), stature(x->rChild)); } //具体规则因树不同而异

template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //更新v及祖先的高度
{ while (x) { updateHeight(x); x = x->parent; } } //可优化：一旦高度未变，即可终止
