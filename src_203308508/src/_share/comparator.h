/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> static bool lt(T * a, T * b) { return lt(*a,*b); } //less than
template <typename T> static bool lt(T & a, T & b) { return a < b; } //less than
template <typename T> static bool eq(T * a, T * b) { return eq(*a,*b); } //equal
template <typename T> static bool eq(T & a, T & b) { return a == b; } //equal