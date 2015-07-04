/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> class PQ { //���ȼ�����PQģ����
public:
   virtual int size() = 0; //��ѯ��ǰ��ģ
   bool empty() { return !size(); } //�ж϶����Ƿ�Ϊ��
   virtual void insert(T) = 0; //���ձȽ���ȷ�������ȼ�����������
   virtual T getMax() = 0; //ȡ�����ȼ���ߵĴ���
   virtual T delMax() = 0; //ɾ�����ȼ���ߵĴ���
};