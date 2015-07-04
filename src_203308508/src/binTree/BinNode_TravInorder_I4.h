/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T, typename VST> //Ԫ�����͡�������
void travIn_I4(BinNodePosi(T) x, VST& visit) { //��������������㷨��������#4������ջ���־λ��
   while (true)
      if (HasLChild(*x)) //��������������
         x = x->lChild; //�������������
      else { //����
         visit(x->data); //���ʵ�ǰ�ڵ㣬��
         while (!HasRChild(*x)) { //����
            if (!(x = x->succ())) return; //����
            visit(x->data); //���ʵ�ǰ�ڵ�
         }
         x = x->rChild; //ת��ǿյ�������
      }
}