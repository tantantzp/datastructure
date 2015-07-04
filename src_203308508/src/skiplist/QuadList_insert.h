/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> QuadlistNodePosi(T) //��e��Ϊp�ĺ�̡�b�����ڲ���Quadlist
Quadlist<T>::insertAfterAbove(T const& e, QuadlistNodePosi(T) p, QuadlistNodePosi(T) b = NULL)
{  _size++; return p->insertAsSuccAbove(e, b);  } //�����½ڵ�λ�ã�below = NULL��