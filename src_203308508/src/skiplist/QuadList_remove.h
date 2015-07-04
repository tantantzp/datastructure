/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //ɾ��Quadlist��λ��p���Ľڵ㣬���ر�ɾ���ڵ����ֵ
T Quadlist<T>::remove(QuadlistNodePosi(T) p) { //assert: pΪQuadlist�еĺϷ�λ��
   T e = p->entry; //���ݴ�ɾ������
   p->pred->succ = p->succ; p->succ->pred = p->pred; //ժ���ڵ�
   release(p); _size--; //Լ����p->data���ɳ���Ա�����ͷ�
   return e; //���ر�ɾ���ڵ����ֵ
}

template <typename T> int Quadlist<T>::clear() { //���Quadlist
   int oldSize = _size;
   while (0 < _size) remove(header->succ); //���ɾ�����нڵ�
   return oldSize;
}