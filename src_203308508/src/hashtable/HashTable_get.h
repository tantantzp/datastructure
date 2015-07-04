/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> V* Hashtable<K, V>::get(K k) //散列表词条查找算法
{  int r = probe4Hit(k); return ht[r] ? &(ht[r]->value) : NULL;  } //禁止词条的key值雷同