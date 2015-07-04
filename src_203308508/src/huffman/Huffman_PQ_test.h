/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "../_share/util.h"
#include "../UniPrint/print.h"

#include "huffman_PQ.h"

extern int* statistics(char*); //根据样本文件统计各字符出现频率
extern HuffForest* initForest(int*); //创建编码树森林
extern HuffTree* generateTree(HuffForest*); //构造编码树
extern HuffTable* generateTable(HuffTree*); //由编码树转换为编码表
extern int encode(HuffTable*, Bitmap*, char*); //明文的编码，返回编码长度
extern void decode(HuffTree*, Bitmap*, int); //二进制串的解码