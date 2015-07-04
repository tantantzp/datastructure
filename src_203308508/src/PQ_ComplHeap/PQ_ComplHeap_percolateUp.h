/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

// ��ȫ����Ѵ��������㷨��������*A�У��Ե�i������ʵʩ���˲���
template <typename T> static Rank percolateUp(Vector<T>* A, Rank i) { //assert: i < A->size()
   while (ParentValid(i)) {
      Rank j = Parent(i); //jΪi֮��
      if (lt(Node(*A, i), Node(*A, j))) break; //һ����ǰ���Ӳ����������˹����������
      swap(Node(*A, i), Node(*A, j)); i = j; //���򣬸��ӽ���λ��
   } //while
   return i; //�����������յִ��λ��
}
