/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\list\list.h"

template <typename T> void checkOrder(List<T> & L) { //判断列表是否整体有序
   int unsorted = 0; //逆序计数器
   L.traverse(CheckOrder<T>(unsorted, L.first()->data)); //进行遍历
   if (0 < unsorted)
      printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
   else
      printf("Sorted\n");
   printf("DISORDERED = %d\n", L.disordered());
}