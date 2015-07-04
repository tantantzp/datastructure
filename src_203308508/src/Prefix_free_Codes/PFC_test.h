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

extern PFCForest* initForest(); //����������ɭ��
extern PFCTree* generateTree(PFCForest*); //���������
extern PFCTable* generateTable(PFCTree*); //�ɱ�����ת��Ϊ�����
extern int encode(PFCTable*, Bitmap&, char*); //���ĵı��룬���ر��볤��
extern void decode(PFCTree*, Bitmap&, int); //�����ƴ��Ľ���