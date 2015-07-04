/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

void reverse(int*, int, int); //重载的倒置算法原型
void reverse(int* A, int n) //数组倒置（算法的初始入口，调用的可能是reverse()的递归版或迭代版）
{ reverse(A, 0, n-1); } //由重载的入口启动递归或迭代算法