/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include<iostream>
using namespace std;

#include "../_share/util.h"
#include "../UniPrint/print.h"

#if defined(DSA_PQ_LEFTHEAP)
#include "../PQ_LeftHeap/PQ_LeftHeap.h"
#elif defined(DSA_PQ_COMPLHEAP)
#include "../PQ_ComplHeap/PQ_ComplHeap.h"
#elif defined(DSA_PQ_LIST)
#include "../PQ_List/PQ_List.h"
#endif
