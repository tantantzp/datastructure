/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\vector\vector.h"

template <typename T> void checkOrder(Vector<T> & V) { //�ж������Ƿ���������
   int unsorted = 0; //���������
   V.traverse(CheckOrder<T>(unsorted, V[0])); //���б���
   if (0 < unsorted)
      printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
   else
      printf("Sorted\n");
}

//template <typename T> void checkOrder(Vector<T> & V) {
//   if (0 < V.disordered())
//      printf("Unsorted with %d adjacent disordered pair(s)\n", V.disordered());
//   else
//      printf("Sorted\n");
//}