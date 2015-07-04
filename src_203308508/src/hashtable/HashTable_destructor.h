/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> Hashtable<K, V>::~Hashtable() { //����ǰ�ͷ�Ͱ���鼰�ǿմ���
   for (int i = 0; i < M; i++) //ע�����Ͱ
      if (ht[i]) release(ht[i]); //�ͷŷǿյ�Ͱ
   release(ht); //�ͷ�Ͱ����
   release(lazyRemoval); //�ͷ�����ɾ�����
}