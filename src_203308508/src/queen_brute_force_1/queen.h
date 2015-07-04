/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include<iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack/stack.h"

#define QUEEN_MAX 20

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //����ģʽ
extern int nSolu; //�������
extern int nCheck; //���Ե��ܴ���

void place5Queens_BruteForce();
void displaySolution(int* solu, int n);
bool collide(int* solu, int k);

void placeQueens(int n, int k);

void place2Queens();
void place3Queens();
void place4Queens();
void place5Queens();