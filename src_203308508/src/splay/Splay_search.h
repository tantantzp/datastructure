/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & Splay<T>::search(const T & e) { //在伸展树中查找关键码e
   BinNodePosi(T) p = searchIn(_root, e, _hot = NULL);
   _root = splay((p ? p : _hot)); //将最后一个被访问的节点伸展至根
   return _root;
} //与其它BST不同，无论查找成功与否，_root都指向最后被访问的节点