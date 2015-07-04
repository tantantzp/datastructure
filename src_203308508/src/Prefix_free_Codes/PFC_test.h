/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#include "../_share/util.h"
#include "../UniPrint/print.h"

#include "PFC.h"

extern PFCForest* initForest(); //创建编码树森林
extern PFCTree* generateTree(PFCForest*); //构造编码树
extern PFCTable* generateTable(PFCTree*); //由编码树转换为编码表
extern int encode(PFCTable*, Bitmap&, char*); //明文的编码，返回编码长度
extern void decode(PFCTree*, Bitmap&, int); //二进制串的解码