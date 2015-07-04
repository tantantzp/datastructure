/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::uniquify() { //�����޳��ظ�Ԫ�أ�Ч�ʸ���
   if (_size < 2) return 0; //ƽ���б���Ȼ���ظ�
   int oldSize = _size; //��¼ԭ��ģ
   ListNodePosi(T) p; ListNodePosi(T) q; //����ָ����ڵĸ��Խڵ�
   for (p = header, q = p->succ; trailer != q; p = q, q = q->succ) //����������ɨ��
      if (p->data == q->data) { remove(q); q = p; } //��p��q��ͬ����ɾ������
   return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
}