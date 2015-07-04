/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\list\list.h"

template <typename T> void checkOrder(List<T> & L) { //�ж��б��Ƿ���������
   int unsorted = 0; //���������
   L.traverse(CheckOrder<T>(unsorted, L.first()->data)); //���б���
   if (0 < unsorted)
      printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
   else
      printf("Sorted\n");
   printf("DISORDERED = %d\n", L.disordered());
}