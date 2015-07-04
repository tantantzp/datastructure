/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> struct Dictionary { //�ʵ�Dictionaryģ����
   virtual int size() = 0; //��ǰ��������
   virtual bool put(K, V) = 0; //�����������ֹ��ͬ����ʱ����ʧ�ܣ�
   virtual V* get(K k) = 0; //��ȡ����
   virtual bool remove(K k) = 0; //ɾ������
};