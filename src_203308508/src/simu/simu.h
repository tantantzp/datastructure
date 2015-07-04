/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once
#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "../queue/queue.h" //�������
#include "Customer.h" //�˿���

int bestWindow(Queue<Customer> window[], int nWin);
void printCustomer(Customer c);
void displayProgress(Queue<Customer> window[], int nWin, int now);
void simulate(int, int);

extern int delay; //���ƽ�����ʾ���ӳ�