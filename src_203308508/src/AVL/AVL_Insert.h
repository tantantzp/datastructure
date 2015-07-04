/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) AVL<T>::insert(const T& e) { //���ؼ���e����AVL����
   BinNodePosi(T) & x = search(e); if (x) return x; //ȷ��Ŀ��ڵ㲻���ڣ������_hot�����ã�
   x = new BinNode<T>(e, _hot); _size++; //�����ڵ�x���˺��丸_hot�������ߣ��游����ʧ�⣩
   for (BinNodePosi(T) g = _hot; g; g = g->parent) { //��x֮���������ϣ�������������g
      if (!AvlBalanced(*g)) { //һ������gʧ�⣬�򣨲��á�3+4���㷨��ʹ֮����
         FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g))); //������������ԭ����
         break; //g����󣬾ֲ������߶ȱ�Ȼ��ԭ�������������ˣ��ʵ����漴����
      } else //����g��Ȼƽ�⣩��ֻ��򵥵�
         updateHeight(g); //������߶ȣ�ע�⣺����gδʧ�⣬�߶���������ӣ�
   } //����ֻ��һ�ε�����������������������ȫ���߶ȱ�Ȼ��ԭ
   return x; //�����½ڵ�
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e
