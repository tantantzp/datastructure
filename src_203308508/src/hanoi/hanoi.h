/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../_share/util.h"
#include "../stack/stack.h"

typedef  int   Disk;

void displayHanoi();
void hanoi(int, Stack<Disk>&, Stack<Disk>&, Stack<Disk>&);
void move(Stack<Disk>&, Stack<Disk>&);

extern int nDisk; //盘子总数
extern Stack<int> Sx, Sy, Sz; //用三个栈模拟三根柱子，每个盘子的半径用整数表示
