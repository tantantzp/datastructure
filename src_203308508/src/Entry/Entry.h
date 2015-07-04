/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> struct Entry { //词条模板类
   K key; V value; //关键码、数值
   Entry(K k, V v) : key(k), value(v) {}; //默认构造函数
   Entry(Entry<K, V> const& e) : key(e.key), value(e.value) {}; //基于克隆的构造函数
   bool operator<(Entry<K, V> const& e) { return key < e.key; } //比较器：小于
   bool operator>(Entry<K, V> const& e) { return key > e.key; } //比较器：大于
   bool operator==(Entry<K, V> const& e) { return key == e.key; } //判等器：等于
   bool operator!=(Entry<K, V> const& e) { return key != e.key; } //判等器：不等于
};