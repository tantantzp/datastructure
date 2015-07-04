/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) Splay<T>::insert(const T& e) { //���ؼ���e������չ����
   if (!_root) { _size++; return _root = new BinNode<T>(e); } //����ԭ��Ϊ�յ��˻����
   if (e == search(e)->data) return _root; //ȷ��Ŀ��ڵ㲻����
   _size++; BinNodePosi(T) t = _root; //�����½ڵ㡣���µ���<=7��ָ������ɾֲ��ع�
   if (_root->data < e) { //�����¸�����t��t->rChildΪ���Һ���
      t->parent = _root = new BinNode<T>(e, NULL, t, t->rChild); //2+3��
      if (HasRChild(*t)) { t->rChild->parent = _root; t->rChild = NULL; } //<=2��
   } else { //�����¸�����t->lChild��tΪ���Һ���
      t->parent = _root = new BinNode<T>(e, NULL, t->lChild, t); //2+3��
      if (HasLChild(*t)) { t->lChild->parent = _root; t->lChild = NULL; } //<=2��
   }
   updateHeightAbove(t); //����t�������ȣ�ʵ����ֻ��_rootһ�����ĸ߶�
   return _root; //�½ڵ��Ȼ��������������֮
} //����e�Ƿ������ԭ���У�����ʱ����_root->data == e
