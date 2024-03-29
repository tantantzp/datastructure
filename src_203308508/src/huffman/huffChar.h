/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#define  N_CHAR  (0x80 - 0x20) //仅以可打印字符为例
struct HuffChar { //Huffman（超）字符
   char ch; int weight; //字符、频率
   HuffChar(char c = '^', int w = 0) : ch(c), weight(w) {};
// 比较器、判等器（各列其一，其余自行补充）
   bool operator<(HuffChar const & hc) { return weight > hc.weight; } //此处故意大小颠倒
   bool operator==(HuffChar const & hc) { return weight == hc.weight; }
};