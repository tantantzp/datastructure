/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & BST<T>::search(const T & e) //��BST�в��ҹؼ���e
{ return searchIn(_root, e, _hot = NULL); } //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ������
