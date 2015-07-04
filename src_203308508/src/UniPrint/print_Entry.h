/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Entry
 ******************************************************************************************/
template <typename K, typename V>
void UniPrint::p(Entry<K, V>& e) //ÒýÓÃ
{  printf("-<"); print(e.key); printf(":"); print(e.value); printf(">-");  }
