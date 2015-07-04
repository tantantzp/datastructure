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

#include "../UniPrint/print.h"

#include "../stack/stack.h"

bool paren(const char exp[], int lo, int hi);
void displaySubstring(const char exp[], int lo, int hi);
void displayProgress(const char exp[], int i, Stack<char> S);
