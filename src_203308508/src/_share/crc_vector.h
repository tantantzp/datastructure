/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "..\vector\vector.h"

template <typename T> void crc(Vector<T> & V) { //统计向量的特征（所有元素之和）
   T crc = 0; V.traverse(Crc<T>(crc)); //以crc为基本操作进行遍历
   printf("CRC ="); print(crc); printf("\n"); //输出统计得到的特征
}