/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����vΪ���ģ�AVL��SPLAY��rbTree�ȣ�BST�����в��ҹؼ���e
static BinNodePosi(T) & searchIn (BinNodePosi(T)& v, const T& e, BinNodePosi(T)& hot) {
   if (!v || (e == v->data)) return v; //���˿�ȷ���ɹ���ʧ�ܣ�����
   hot = v; //�ȼ��µ�ǰ�ڵ㣬Ȼ����
   return searchIn(((e < v->data) ? v->lChild : v->rChild), e, hot); //�ݹ����
} //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ��������ʧ��ʱ������NULL