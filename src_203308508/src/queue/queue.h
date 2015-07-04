/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../List/List.h" //��ListΪ����
template <typename T> class Queue: public List<T> { //����ģ���ࣨ�̳�Listԭ�нӿڣ�
public: //size()��empty()�Լ��������Žӿھ���ֱ������
   void enqueue(T const& e) { insertAsLast(e); } //��ӣ�β������
   T dequeue() { return remove(first()); } //���ӣ��ײ�ɾ��
   T& front() { return first()->data; } //����
};

#include "queue_implementation.h"