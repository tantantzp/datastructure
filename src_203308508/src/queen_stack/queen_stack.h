/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include "../stack/stack.h" //ջ
#include "queen.h" //����ʺ���

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //����ģʽ
extern int nSolu; //�������
extern int nCheck; //���Ե��ܴ���

void placeQueens(int);
void displayRow(Queen& q, int);
void displayProgress(Stack<Queen>& S, int);