/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <stdlib.h>
#include <time.h> //ͨ���õ�ǰʱ�������������

/******************************************************************************************
 * ��[0, range)���������һ����
 ******************************************************************************************/
static int dice(int range) { return rand()%range; } //ȡ[0, range)�е��������
static int dice(int lo, int hi) { return lo + rand()%(hi-lo); } //ȡ[lo, hi)�е��������
static float dice(float range) { return rand()%(1000*(int)range)/(float)1000.; }
static double dice(double range) { return rand()%(1000*(int)range)/(double)1000.; }
static char dice(char range) { return (char)(32+rand()%96); }