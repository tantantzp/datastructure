/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool Splay<T>::remove(const T & e) { //����չ����ɾ���ؼ���e
   if (!_root || (e != search(e)->data)) return false; //�����ջ�Ŀ��ؼ��벻���ڣ����޷�ɾ��
   BinNodePosi(T) w = _root; //assert: ��search()��ڵ�e�ѱ���չ������
   if (!HasLChild(*_root)) { //��������������ֱ��ɾ��
      _root = _root->rChild; if (_root) _root->parent = NULL;
   } else if (!HasRChild(*_root)) { //������������Ҳֱ��ɾ��
      _root = _root->lChild; if (_root) _root->parent = NULL;
   } else { //����������ͬʱ���ڣ���
      BinNodePosi(T) lTree = _root->lChild;
      lTree->parent = NULL; _root->lChild = NULL; //��ʱ���������г�
      _root = _root->rChild; _root->parent = NULL; //ֻ����������
      search(w->data); //��ԭ����ΪĿ�꣬��һ�Σ��ض�ʧ�ܵģ�����
///// assert: ���ˣ�����������С�ڵ����չ�������ң�������ͬ�ڵ㣩���������ؿգ�����
      _root->lChild = lTree; lTree->parent = _root; //ֻ�轫ԭ�������ӻ�ԭλ����
   }
   release(w->data); release(w); _size--; //�ͷŽڵ㣬���¹�ģ
   if (_root) updateHeight(_root); //�˺������ǿգ��������ĸ߶���Ҫ����
   return true; //���سɹ���־
} //��Ŀ��ڵ�����ұ�ɾ��������true�����򷵻�false
