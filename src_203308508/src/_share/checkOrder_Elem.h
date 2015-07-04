/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct CheckOrder { //函数对象：判断一个T类对象是否局部有序
   T pred; int & u;
   CheckOrder(int& unsorted, T& first) : pred(first), u(unsorted){ }
   virtual void operator()(T& e) { if (pred > e) u++; pred = e; }
};
