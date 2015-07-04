/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Vector/Vector.h" //������Ϊ����
template <typename T> class Stack: public Vector<T> { //������������ջģ����
public: //size()��empty()�Լ��������Žӿھ���ֱ������
   void push(T const & e) { insert(size(), e); } //��ջ
   T pop() { return remove(size()-1); } //��ջ
   T& top() { return (*this)[size()-1]; } //ȡ��
};

#include "stack_implementation.h"