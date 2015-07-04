/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../PQ_LEFTHeap/PQ_LeftHeap.h" //用PQ_LeftHeap实现
typedef PQ_LeftHeap<HuffTree*> HuffForest; //Huffman森林