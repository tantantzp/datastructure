/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Skiplist
 ******************************************************************************************/

template <typename K, typename V> //e、value和比较器
void UniPrint::p(Skiplist<K, V>& s) { //引用
   printf("%s[%d]*%d*%d:\n", typeid(s).name(), &s, s.level(), s.size()); //基本信息
   s.traverse(print); //通过print()遍历输出所有元素
   printf("\n");
}
