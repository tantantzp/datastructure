/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 打印输出PQ_LeftHeap
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p(PQ_LeftHeap<T> & lh) { //引用
   printf("%s*%d:\n", typeid(lh).name(), lh.size()); //基本信息
   print(lh.heap);
}