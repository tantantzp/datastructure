/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "simu.h"

int bestWindow(Queue<Customer> windows[], int nWin) { //Ϊ�µ��˿�ȷ����Ѷ���
   int minSize = windows[0].size(), optiWin = 0; //���Ŷ��У����ڣ�
   for (int i = 1; i < nWin; i++) //�����д�����
      if (minSize > windows[i].size()) //��ѡ��
         { minSize = windows[i].size(); optiWin = i; } //���������
   return optiWin; //����
}