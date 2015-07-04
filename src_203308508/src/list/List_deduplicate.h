/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::deduplicate() { //�޳������б��е��ظ��ڵ�
   if (_size < 2) return 0; //ƽ���б���Ȼ���ظ�
   int oldSize = _size; //��¼ԭ��ģ
   ListNodePosi(T) p = header; Rank r = 0; //p���׽ڵ㿪ʼ
   while (trailer != (p = p->succ)) { //����ֱ��ĩ�ڵ�
      ListNodePosi(T) q = find(p->data, r, p); //��p��r�����棩ǰ���в�����ͬ��
      q ? remove(q) : r++; //����ȷ���ڣ���ɾ��֮�������ȼ�һ
   } //assert: ѭ�������е�����ʱ�̣�p������ǰ��������ͬ
   return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
}