/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�����±����������ͨ����ֱ�ӷ����б�ڵ㣨�䷽�㣬Ч�ʵͣ������ã�
ListNodePosi(T) List<T>::operator[](int r) const { //assert: 0 <= r < size
   ListNodePosi(T) p = first(); //���׽ڵ����
   while (0 < r--) p = p->succ; //˳����r���ڵ㼴��
   return p; //Ŀ��ڵ�
}