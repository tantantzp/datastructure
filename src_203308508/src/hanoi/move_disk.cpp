/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/


#include "hanoi.h"

void move(Stack<Disk>& Sa, Stack<Disk>& Sb) { //将Sa顶部的盘子移至Sb顶部
   Sb.push(Sa.pop()); //pop a disk from stack A and push it into stack B
   displayHanoi();
}