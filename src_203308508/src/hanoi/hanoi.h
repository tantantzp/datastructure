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

extern int nDisk; //��������
extern Stack<int> Sx, Sy, Sz; //������ջģ���������ӣ�ÿ�����ӵİ뾶��������ʾ
