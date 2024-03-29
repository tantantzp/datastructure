/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 将PQ_PQ_LeftHeap各方法的实现部分，简洁地引入PQ_PQ_LeftHeap.h
 * 效果等同于将这些实现直接汇入PQ_PQ_LeftHeap.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/
#include "../_share/release.h"
#include "../_share/util.h"

#include "PQ_LeftHeap_Insert.h"
#include "PQ_LeftHeap_getMax.h"
#include "PQ_LeftHeap_delMax.h"
#include "PQ_LeftHeap_Merge.h"
