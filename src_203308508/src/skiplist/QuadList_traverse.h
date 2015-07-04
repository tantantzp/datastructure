/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����Quadlist���Ը��ڵ�����ʵʩvisit����
void Quadlist<T>::traverse(void (*visit)(T&)) { //���ú���ָ����ƣ�ֻ����ֲ����޸�
   QuadlistNodePosi(T) p = header;
   while ((p = p->succ) != trailer) visit(p->data);
}

template <typename T> template <typename VST> //����Quadlist���Ը��ڵ�����ʵʩvisit����
void Quadlist<T>::traverse(VST& visit) { //���ú���������ƣ���ȫ�����޸�
   QuadlistNodePosi(T) p = header;
   while ((p = p->succ) != trailer) visit(p->data);
}