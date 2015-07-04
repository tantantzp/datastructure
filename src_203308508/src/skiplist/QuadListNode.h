/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Entry/Entry.h"
#define QuadlistNodePosi(T)  QuadlistNode<T>* //��ת��ڵ�λ��
template <typename T> class QuadlistNode{ //QuadlistNodeģ����
public:
// ��Ա
   T entry; //��ֵ
   QuadlistNodePosi(T) pred;  QuadlistNodePosi(T) succ;  //ǰ�������
   QuadlistNodePosi(T) above; QuadlistNodePosi(T) below; //���ڡ�����
// ���캯��
   QuadlistNode() {} //���header��trailer�Ĺ���
   QuadlistNode //Ĭ�Ϲ�����
      ( T e, QuadlistNodePosi(T) p = NULL, QuadlistNodePosi(T) s = NULL,
      QuadlistNodePosi(T) a = NULL, QuadlistNodePosi(T) b = NULL)
      : entry(e), pred(p), succ(s), above(a), below(b) {}
// �����ӿ�
   QuadlistNodePosi(T) insertAsSuccAbove //�����½ڵ㣬�Ե�ǰ�ڵ�Ϊǰ�����Խڵ�bΪ����
      (T const & e, QuadlistNodePosi(T) b = NULL);
};

#include "QuadlistNode_implementation.h"