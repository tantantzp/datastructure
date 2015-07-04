/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#define  N_CHAR  (0x80 - 0x20) //���Կɴ�ӡ�ַ�Ϊ��
struct HuffChar { //Huffman�������ַ�
   char ch; int weight; //�ַ���Ƶ��
   HuffChar(char c = '^', int w = 0) : ch(c), weight(w) {};
// �Ƚ������е�����������һ���������в��䣩
   bool operator<(HuffChar const & hc) { return weight > hc.weight; } //�˴������С�ߵ�
   bool operator==(HuffChar const & hc) { return weight == hc.weight; }
};