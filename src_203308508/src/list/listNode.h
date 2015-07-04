/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

typedef int Rank; //��
#define ListNodePosi(T) ListNode<T>* //�б�ڵ�λ��

template <typename T> struct ListNode { //�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
// ��Ա
   T data; ListNodePosi(T) pred; ListNodePosi(T) succ; //��ֵ��ǰ�������
// ���캯��
   ListNode() {} //���header��trailer�Ĺ���
   ListNode( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
      : data(e), pred(p), succ(s) {} //Ĭ�Ϲ�����
// �����ӿ�
   ListNodePosi(T) insertAsPred(T const & e); //������ǰ�ڵ�֮ǰ�����½ڵ�
   ListNodePosi(T) insertAsSucc(T const & e); //���浱ǰ�ڵ�֮������½ڵ�
};

#include "listNode_implementation.h"