/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes(ListNodePosi(T) p, int n) { //p�Ϸ�����������n-1�����̽ڵ�
   init(); //����ͷ��β�ڱ��ڵ㲢����ʼ��
   while(n--) { insertAsLast(p->data); p = p->succ; } //������p��n��������Ϊĩ�ڵ����
}