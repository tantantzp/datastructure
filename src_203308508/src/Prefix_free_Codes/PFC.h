/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print.h"

/******************************************************************************************
 * PFC编码使用的数据结构
 ******************************************************************************************/
#include "../BinTree/BinTree.h" //用BinTree实现PFC树
typedef BinTree<char> PFCTree; //PFC树

#include "../Vector/Vector.h" //用Vector实现PFC森林
typedef Vector<PFCTree*> PFCForest; //PFC森林

#include "../Bitmap/Bitmap.h" //使用位图表示二进制编码
#include "../Skiplist/Skiplist.h" //使用跳转表表示编码表：(字符，编码串）
typedef Skiplist<char, char*> PFCTable; //PFC编码表

#define  N_CHAR  (0x80 - 0x20) //只考虑可打印字符
