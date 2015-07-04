/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //assert: p为合法位置，且至少有n-1个后继节点
List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p, n); } //复制列表中自位置p起的n项

template <typename T>
List<T>::List(List<T> const & L) { copyNodes(L.first(), L._size); } //整体复制列表L

template <typename T> //assert: r+n <= L._size
List<T>::List(List<T> const & L, int r, int n) { copyNodes(L[r], n); } //复制L中自第r项起的n项