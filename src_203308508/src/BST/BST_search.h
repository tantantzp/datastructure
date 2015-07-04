/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & BST<T>::search(const T & e) //在BST中查找关键码e
{ return searchIn(_root, e, _hot = NULL); } //返回目标节点位置的引用，以便后续插入、删除操作
