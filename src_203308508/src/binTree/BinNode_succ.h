/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::succ() { //��λ�ڵ�v��ֱ�Ӻ��
   BinNodePosi(T) s = this; //��¼��̵���ʱ����
   if (rChild) { //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
      s = rChild; //��������
      while (HasLChild(*s)) s = s->lChild; //�����С���Ľڵ�
   } else { //����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
      while (IsRChild(*s)) s = s->parent; //������������֧�����ϳ����Ϸ��ƶ�
      s = s->parent; //����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ�̣�������ڣ�
   }
  return s;
}