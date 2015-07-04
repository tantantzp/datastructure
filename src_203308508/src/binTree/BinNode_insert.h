/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //��e��Ϊ��ǰ�ڵ�����Ӳ��������
BinNodePosi(T) BinNode<T>::insertAsLC(T const & e) {  return lChild = new BinNode(e, this);  }

template <typename T> //��e��Ϊ��ǰ�ڵ���Һ��Ӳ��������
BinNodePosi(T) BinNode<T>::insertAsRC(T const & e) {  return rChild = new BinNode(e, this);  }
