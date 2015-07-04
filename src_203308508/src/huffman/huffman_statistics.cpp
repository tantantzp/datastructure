/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

int* statistics(char* sample_text_file) { //ͳ���ַ�����Ƶ��
   int* freq = new int[N_CHAR];  //����ͳ����������ʣ����������¼���ַ����ִ���
   memset(freq, 0, sizeof(int)*N_CHAR); //����
   FILE* fp = fopen(sample_text_file, "r"); //assert: �ļ������ҿ���ȷ��
   char ch;
   while (0 < fscanf(fp, "%c", &ch)) //���ɨ�������ļ��е�ÿ���ַ�
      if (ch >= 0x20) freq[ch-0x20]++; //�ۼƶ�Ӧ�ĳ��ִ���
   fclose(fp); return freq;
}