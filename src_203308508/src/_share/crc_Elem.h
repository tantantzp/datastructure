/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct Crc { //函数对象：累计T类对象的特征（比如总和），以便校验对象集合
   T & c;
   Crc(T & crc) : c(crc) {}
   virtual void operator()(T& e) { c += e; } //假设T可直接相加
};