/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> V* Skiplist<K, V>::get(K k) { //跳转表词条查找算法
   if (empty()) return NULL;
   ListNode<Quadlist<Entry<K, V>*>*>* qlist = first(); //从顶层Quadlist的
   QuadlistNode<Entry<K, V>*>* p = qlist->data->first(); //首节点开始
   return skipSearch(qlist, p, k) ? &(p->entry->value) : NULL; //查找并报告
} //有多个命中时靠后者优先