/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

inline Cell* advance(Cell* cell) { //�ӵ�ǰλ��ת�����ڸ��
   Cell* next;
   switch (cell->outgoing) {
      case EAST:  next = cell + LABY_MAX; next->incoming = WEST;  break; //��
      case SOUTH: next = cell + 1;        next->incoming = NORTH; break; //����
      case WEST:  next = cell - LABY_MAX; next->incoming = EAST;  break; //����
      case NORTH: next = cell - 1;        next->incoming = SOUTH; break; //��
      default : exit(-1);
   }
   return next;
}