/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "simu.h"

/******************************************************************************************
 * ��ʾ��ǰ�������ڣ��������
 ******************************************************************************************/
void displayProgress(Queue<Customer> windows[], int nWin, int now) {
   system("cls"); //����
   printf("============ Time: %4d ============\n", now);
   for (int i = 0; i < nWin; i++) { //��ÿ�����ڣ��ֱ�
      printf("Window #%c:  ", 'A'+i); //������ڱ��
      windows[i].traverse(printCustomer); printf("\n"); //�г������е����й˿�
   }
}