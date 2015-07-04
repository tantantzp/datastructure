/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) //���½ڵ�x�߶�
{ return x->height = 1 + max(stature(x->lChild), stature(x->rChild)); } //�������������ͬ����

template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //����v�����ȵĸ߶�
{ while (x) { updateHeight(x); x = x->parent; } } //���Ż���һ���߶�δ�䣬������ֹ
