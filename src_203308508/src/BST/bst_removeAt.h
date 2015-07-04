/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST�ڵ�ɾ���㷨��ɾ��λ��v��ָ�Ľڵ㣨ȫ�־�̬ģ�庯����������AVL��Splay��RedBlack�ȸ���BST��
 * vͨ���ɴ�ǰ�Ĳ���ȷ������ȷ�Ϸ�NULL�󷽵��ñ��������ʱ�ɾ���ɹ�
 * ��searchIn��ͬ������֮ǰ���ؽ�hot�ÿ�
 * ����ֵָ��ʵ�ʱ�ɾ���ڵ�Ľ����ߣ�hotָ��ʵ�ʱ�ɾ���ڵ�ĸ��ס������߾��п�����NULL
 ******************************************************************************************/
template <typename T> static BinNodePosi(T) removeAt(BinNodePosi(T)& v, BinNodePosi(T)& hot) {
   BinNodePosi(T) w = v; //ʵ�ʱ�ժ���Ľڵ㣬��ֵͬv
   BinNodePosi(T) succ = NULL; //ʵ�ʱ�ɾ���ڵ�Ľ�����
   if (!HasLChild(*v)) //��*v��������Ϊ�գ����
      succ = v = v->rChild; //ֱ�ӽ�*v�滻Ϊ��������
   else if (!HasRChild(*v)) //��������Ϊ�գ����
      succ = v = v->lChild; //�ԳƵش�����ע�⣺��ʱsucc != NULL
   else { //���������������ڣ���ѡ��v��ֱ�Ӻ����Ϊʵ�ʱ�ժ���ڵ㣬Ϊ����Ҫ
      w = w->succ(); //�����������У��ҵ�*v��ֱ�Ӻ��*w
      swap(v->data, w->data); //����*v��*w������Ԫ��
      BinNodePosi(T) u = w->parent;
      ((u == v) ? u->rChild : u->lChild) = succ = w->rChild; //����ڵ�*w
   }
   hot = w->parent; //��¼ʵ�ʱ�ɾ���ڵ�ĸ���
   if (succ) succ->parent = hot; //������ɾ���ڵ�Ľ�������hot����
   release(w->data); release(w); //�ͷű�ժ���ڵ�
   return succ; //���ؽ�����
}
