/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "fac.h"

int main(int argc, char* argv[]) { //Ω◊≥À‘ÀÀ„≤‚ ‘
   for(int i = 0; i < 25; i++)
      printf("\t%d\t%22I64d\t%22I64d\n", i, facI(i), facR(i));
   return 0;
}