/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> QuadlistNodePosi(T) //��e��Ϊ��ǰ�ڵ�ĺ�̡�b�����ڲ���Quadlist
QuadlistNode<T>::insertAsSuccAbove(T const & e, QuadlistNodePosi(T) b = NULL) {
   QuadlistNodePosi(T) x = new QuadlistNode<T>(e, this, succ, NULL, b); //�����½ڵ�
   succ->pred = x; succ = x; //����ˮƽ��������
   if (b) b->above = x; //���ô�ֱ��������
   return x; //�����½ڵ��λ��
}