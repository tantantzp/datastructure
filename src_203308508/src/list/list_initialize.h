/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::init() { //�б��ʼ�����ڴ����б����ʱͳһ����
   header = new ListNode<T>; //����ͷ�ڱ��ڵ�
   trailer = new ListNode<T>; //����β�ڱ��ڵ�
   header->succ = trailer; header->pred = NULL;
   trailer->pred = header; trailer->succ = NULL;
   _size = 0; //��¼��ģ
}