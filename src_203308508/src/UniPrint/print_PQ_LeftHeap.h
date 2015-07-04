/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��ӡ���PQ_LeftHeap
 ******************************************************************************************/
template <typename T> //Ԫ������
void UniPrint::p(PQ_LeftHeap<T> & lh) { //����
   printf("%s*%d:\n", typeid(lh).name(), lh.size()); //������Ϣ
   print(lh.heap);
}