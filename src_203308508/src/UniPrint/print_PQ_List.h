/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 打印输出PQ_List
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p(PQ_List<T> & pq) { //引用
   printf("%s*%d:\n", typeid(pq).name(), pq.size()); //基本信息
   print(pq.list); printf("\n");
}
