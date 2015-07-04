/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::getMax() //��ȡ�ǿ���ʽ�������ȼ���ߵĴ���
{ return heap->root()->data; } //���մ˴�Լ�����Ѷ������ȼ���ߵĴ���