/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��ݷ�ʽ
 ******************************************************************************************/
#define  Node(PQ, i)       ((PQ)[i])
#define  InHeap(n, i)      (((-1) < (i)) && ((i) < (n))) //�ж�PQ[i]�Ƿ�Ϸ��ڵ�
#define  Parent(i)         ((i-1) >> 1) //PQ[i]�ĸ��ڵ㣨floor((i-1)/2)��i����������
#define  LastInternal(n)   Parent(n-1) //���һ���ڲ��ڵ㣨��ĩ�ڵ�ĸ��ף�
#define  LChild(i)         (1 + ((i) << 1)) //PQ[i]������
#define  RChild(i)         ((1 + (i)) << 1) //PQ[i]���Һ���
#define  ParentValid(i)    (0 < i) //�ж�PQ[i]�Ƿ��и���
#define  LChildValid(n, i) InHeap(n, LChild(i)) //�ж�PQ[i]�Ƿ���һ�����󣩺���
#define  RChildValid(n, i) InHeap(n, RChild(i)) //�ж�PQ[i]�Ƿ�����������
#define  Bigger(PQ, i, j)  (lt(Node(PQ, i), Node(PQ, j)) ? j : i) //ȡ���ߣ���ʱǰ�����ȣ�
#define  ProperParent(PQ, n, i) \
            (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : \
            (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : i \
            ) \
            ) //���ӣ����ࣩ�����еĴ��ߣ����ʱ���ڵ����ȣ���˿ɱ��ⲻ��Ҫ�Ľ�����