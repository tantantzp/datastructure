/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Hashtable<K, V>::remove(K k) { //ɢ�б����ɾ���㷨
   int r = probe4Hit(k); if (!ht[r]) return false; //��Ӧ����������ʱ���޷�ɾ��
   release(ht[r]); ht[r] = NULL; markAsRemoved(r); N--; return true;
   //�����ͷ�Ͱ�д�������������ɾ����ǣ������´�������
}