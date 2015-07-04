/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::traverse(void (*visit)(T&)) //���ú���ָ����Ƶı���
{  for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);  }

template <typename T> template <typename VST> //Ԫ�����͡�������
void List<T>::traverse(VST& visit) //���ú���������Ƶı���
{  for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);  }