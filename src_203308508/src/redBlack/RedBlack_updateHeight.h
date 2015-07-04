/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int RedBlack<T>::updateHeight(BinNodePosi(T) x) { //���º�����ڵ�߶�
   x->height = max(stature(x->lChild), stature(x->rChild)); //����һ��ڸ߶���ȣ����ǳ���˫��ʱ
/*DSA*/// ������и��ڵ����Һ��ӵĺڸ߶�ͨ�����
/*DSA*/// ����֮����ȡ����ֵ���Ǳ�����ɾ���ڵ���ƽ����������У���ȷ���±�ɾ���ڵ㸸�׵ĺڸ߶�
/*DSA*/// ����rotateAt()����ݱ�ɾ���ڵ������ߣ��߶�Сһ�����ø��ڵ�ĺڸ߶�
   return IsBlack(x) ? x->height++ : x->height; //����ǰ�ڵ�Ϊ�ڣ����������
} //BinNode����ʱĬ�ϸ߶�ȡ0�������нڵ�ĺڸ߶ȱ�ԭ������һ�����ڲ���Ӱ�쵽�����㷨�еıȽ��ж�
