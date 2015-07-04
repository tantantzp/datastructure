/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //重载下标操作符，以通过秩直接访问列表节点（虽方便，效率低，需慎用）
ListNodePosi(T) List<T>::operator[](int r) const { //assert: 0 <= r < size
   ListNodePosi(T) p = first(); //从首节点出发
   while (0 < r--) p = p->succ; //顺数第r个节点即是
   return p; //目标节点
}