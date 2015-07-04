/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

inline Cell* neighbor(Cell* cell) { //��ѯ��ǰλ�õ����ڸ��
   switch (cell->outgoing) {
      case EAST  : return cell + LABY_MAX; //��
      case SOUTH : return cell + 1;        //����
      case WEST  : return cell - LABY_MAX; //����
      case NORTH : return cell - 1;        //��
      default    : exit(-1);
   }
}