/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T, typename VST> //Ԫ�����͡�������
void travPre_I1(BinNodePosi(T) x, VST& visit) { //��������������㷨��������#1��
   Stack<BinNodePosi(T)> S; //����ջ
   if (x) S.push(x); //���ڵ���ջ
   while (!S.empty()) { //��ջ���֮ǰ����ѭ��
      x = S.pop(); visit(x->data); //���������ʵ�ǰ�ڵ㣬��ǿպ��ӵ���ջ����Ϊ
      if (HasRChild(*x)) S.push(x->rChild); if (HasLChild(*x)) S.push(x->lChild); //���Һ���
   }
}