/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/


#include "hanoi.h"

void hanoi( //HanoiËþÓÎÏ·Ä£Äâ
   int n, //#Discs
   Stack<Disk>& Sx,   //From
   Stack<Disk>& Sy,   //Via
   Stack<Disk>& Sz)   //To
{
   if (n > 0)   {
      hanoi(n-1, Sx, Sz, Sy); //move the top n-1 disks from X to Y (via Z)
      move(Sx, Sz); //move the last disk from X to Z
      hanoi(n-1, Sy, Sx, Sz); //move n-1 disks from Y to Z (via X)
   }
}