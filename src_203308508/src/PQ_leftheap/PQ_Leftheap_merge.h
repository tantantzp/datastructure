/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> static void exchangeChildren(BinNodePosi(T) v) //���Һ��ӶԻ�
{ BinNodePosi(T) t =  v->lChild; v->lChild = v->rChild; v->rChild = t; }

// �ϲ���a��bΪ���ڵ��������ʽ�ѣ�����ǰ�����ȼ�����
template <typename T> static BinNodePosi(T) merge1(BinNodePosi(T) a, BinNodePosi(T) b) {
   if (!HasLChild(*a)) { //aû������
      a->lChild = b; b->parent = a; //ֱ�ӽ�b��Ϊa������
   } else { //����
      a->rChild = merge(a->rChild, b); //��b��a�����ӶѺϲ�
      a->rChild->parent = a; //�����¸��ӹ�ϵ
      if (a->lChild->npl < a->rChild->npl) //�ϲ�����a���Ӷѵ�npl��С����
         exchangeChildren(a); //����a�������Ӷѡ�����˿ɱ�֤���Ӷѵ�npl��С
      a->npl = a->rChild->npl + 1; //����a��npl
   }
   return a; //���غϲ���ĶѶ�
}

// ����������ȼ�ȷ�����˵ķ�ʽ���ϲ���a��bΪ���ڵ��������ʽ��
template <typename T> static BinNodePosi(T) merge(BinNodePosi(T) a, BinNodePosi(T) b) {
   if (!a) return b; //�˻����
   if (!b) return a; //�˻����
   return //һ�����
      lt(a->data, b->data) ? //���ݴ��ϲ��Ӷѵ�������ȼ���ȷ���ϲ�����
         merge1(b, a) : //b���ȼ�����ʱ
         merge1(a, b) ; //a���ȼ�����ʱ
} //�㷨ֻ����ṹ�ϲ����ѵĹ�ģ�����ϲ�����߸�������Ӧ�ĸ���