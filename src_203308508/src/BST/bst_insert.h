/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BST<T>::insert(const T& e) { //���ؼ���e����BST����
   BinNodePosi(T) & x = search(e); if (x) return x; //ȷ��Ŀ��ڵ㲻���ڣ������_hot�����ã�
   x = new BinNode<T>(e, _hot); //�����½ڵ�x����eΪ�ؼ��룬��_hotΪ��
   _size++; //����ȫ����ģ
   updateHeightAbove(x); //����x�����������ȵĸ߶�
   return x;
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e
