/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "..\list\list.h"

template <typename T> void increase(List<T> & L) //统一递增列表中的各元素
{  L.traverse(Increase<T>());  } //以Increase<T>()为基本操作进行遍历