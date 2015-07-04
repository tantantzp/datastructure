/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BinNode״̬�����ʵ��ж�
 ******************************************************************************************/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x) || HasRChild(x)) //����ӵ��һ������
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //ͬʱӵ����������
#define IsLeaf(x) (!HasChild(x))

/******************************************************************************************
 * ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
 ******************************************************************************************/
#define sibling(p) ( \
   IsLChild(*(p)) ? \
      (p)->parent->rChild : \
      (p)->parent->lChild \
) //�ֵ�

#define uncle(x) ( \
   IsLChild(*((x)->parent)) ? \
      (x)->parent->parent->rChild : \
      (x)->parent->parent->lChild \
) //����

#define FromParentTo(x) ( \
   IsRoot(x) ? _root : ( \
   IsLChild(x) ? (x).parent->lChild : (x).parent->rChild \
   ) \
) //���Ը��׵�ָ��
