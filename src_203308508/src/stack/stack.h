/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Vector/Vector.h" //以向量为基类
template <typename T> class Stack: public Vector<T> { //由向量派生的栈模板类
public: //size()、empty()以及其它开放接口均可直接沿用
   void push(T const & e) { insert(size(), e); } //入栈
   T pop() { return remove(size()-1); } //出栈
   T& top() { return (*this)[size()-1]; } //取顶
};

#include "stack_implementation.h"