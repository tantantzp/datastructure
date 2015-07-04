/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "print.h"

/******************************************************************************************
 * ��������
 ******************************************************************************************/
void UniPrint::p(int e) { printf(" %04d", e); }
void UniPrint::p(float e) { printf(" %4.1f", e); }
void UniPrint::p(double e) { printf(" %4.1f", e); }
void UniPrint::p(char e) { printf(" %c", (31<e) && (e<128) ? e : '$'); }
void UniPrint::p(VStatus e) {
   switch (e) {
      case UNDISCOVERED:   printf("U"); break;
      case DISCOVERED:     printf("D"); break;
      case VISITED:        printf("V"); break;
      default:             printf("X"); break;
   }
}
void UniPrint::p(EStatus e) {
   switch (e) {
      case UNDETERMINED:   printf("U"); break;
      case TREE:           printf("T"); break;
      case CROSS:          printf("C"); break;
      case BACKWARD:       printf("B"); break;
      case FORWARD:        printf("F"); break;
      default:             printf("X"); break;
   }
}
