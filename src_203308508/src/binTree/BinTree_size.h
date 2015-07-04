/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //ͳ�ƶ�����������ģ
int BinTree<T>::size(BinNodePosi(T) x) //assert: xΪ�������еĺϷ�λ��
{  return x ? size(x->lChild)+size(x->RChild) : 0;  }
