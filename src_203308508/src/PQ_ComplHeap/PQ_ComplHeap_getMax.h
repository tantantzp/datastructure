/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_ComplHeap<T>::getMax() //��ȡ�ǿ���ȫ����������ȼ���ߵĴ���
{  return (*heap)[0];  } //���մ˴�Լ���������״��������ȼ���ߵĴ���