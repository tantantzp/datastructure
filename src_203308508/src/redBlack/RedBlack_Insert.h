/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) RedBlack<T>::insert(const T& e) { //���ؼ���e��������
   BinNodePosi(T) & x = search(e); if (x) return x; //ȷ��Ŀ��ڵ㲻���ڣ������_hot�����ã�
   x = new BinNode<T>(e, _hot, NULL, NULL, -1); _size++; //������ڵ�x����_hotΪ�����ڸ߶�-1
   solveDoubleRed(x); return x; //��˫�������󣬼��ɷ���
} //����e�Ƿ������ԭ���У�����ʱ����x->data == e
