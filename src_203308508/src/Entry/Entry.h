/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> struct Entry { //����ģ����
   K key; V value; //�ؼ��롢��ֵ
   Entry(K k, V v) : key(k), value(v) {}; //Ĭ�Ϲ��캯��
   Entry(Entry<K, V> const& e) : key(e.key), value(e.value) {}; //���ڿ�¡�Ĺ��캯��
   bool operator<(Entry<K, V> const& e) { return key < e.key; } //�Ƚ�����С��
   bool operator>(Entry<K, V> const& e) { return key > e.key; } //�Ƚ���������
   bool operator==(Entry<K, V> const& e) { return key == e.key; } //�е���������
   bool operator!=(Entry<K, V> const& e) { return key != e.key; } //�е�����������
};