/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../queue/queue.h" //�������
template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travLevel(VST& visit) { //��������α����㷨
   Queue<BinNodePosi(T)> Q; //��������
   Q.enqueue(this); //���ڵ����
   while (!Q.empty()) { //�ڶ����ٴα��֮ǰ����������
      BinNodePosi(T) x = Q.dequeue(); visit(x->data); //ȡ�����׽ڵ㲢����֮
      if (HasLChild(*x)) Q.enqueue(x->lChild); //�������
      if (HasRChild(*x)) Q.enqueue(x->rChild); //�Һ������
   }
}