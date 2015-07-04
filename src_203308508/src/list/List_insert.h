/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{  _size++; return header->insertAsSucc(e);  } //e当作首节点插入

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{  _size++; return trailer->insertAsPred(e);  } //e当作末节点插入

template <typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)
{  _size++; return p->insertAsPred(e);  } //e当作p的前驱插入

template <typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)
{  _size++; return p->insertAsSucc(e);  } //e当作p的后继插入
