/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct CheckOrder { //���������ж�һ��T������Ƿ�ֲ�����
   T pred; int & u;
   CheckOrder(int& unsorted, T& first) : pred(first), u(unsorted){ }
   virtual void operator()(T& e) { if (pred > e) u++; pred = e; }
};
