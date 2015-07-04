/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 将List各方法的实现部分，简洁地引入List.h
 * 效果等同于将这些实现直接汇入List.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/
#include "../_share/release.h"
#include "../_share/util.h"

#include "ListNode.h"

#include "List_bracket.h"

#include "List_initialize.h"
#include "List_copyNodes.h"
#include "List_constructor_by_copying.h"
#include "List_destructor.h"

#include "list_disordered.h"

#include "List_find.h"
#include "List_search.h"

#include "List_insert.h"
#include "List_remove.h"
#include "List_clear.h"

#include "List_traverse.h"

#include "List_sort.h"
#include "List_insertionSort.h"
#include "List_selectMax.h"
#include "List_selectionSort.h"
#include "List_merge.h"
#include "List_mergeSort.h"

#include "List_deduplicate.h"
#include "List_uniquify.h"
