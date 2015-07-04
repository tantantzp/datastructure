/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\vector\vector.h"

template <typename T> void crc(Vector<T> & V) { //ͳ������������������Ԫ��֮�ͣ�
   T crc = 0; V.traverse(Crc<T>(crc)); //��crcΪ�����������б���
   printf("CRC ="); print(crc); printf("\n"); //���ͳ�Ƶõ�������
}