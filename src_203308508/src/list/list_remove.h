/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T List<T>::remove(ListNodePosi(T) p) { //ɾ���Ϸ�λ��p���ڵ㣬��������ֵ
   T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
   p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
   delete p; _size--; //�ͷŽڵ㣬���¹�ģ
   return e; //���ر��ݵ���ֵ
}