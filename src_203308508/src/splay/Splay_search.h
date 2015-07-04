/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & Splay<T>::search(const T & e) { //����չ���в��ҹؼ���e
   BinNodePosi(T) p = searchIn(_root, e, _hot = NULL);
   _root = splay((p ? p : _hot)); //�����һ�������ʵĽڵ���չ����
   return _root;
} //������BST��ͬ�����۲��ҳɹ����_root��ָ����󱻷��ʵĽڵ�