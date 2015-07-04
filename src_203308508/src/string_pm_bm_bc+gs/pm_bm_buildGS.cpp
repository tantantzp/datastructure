/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../string_pm/string_pm_test.h"

int* buildSS(char* P) { //�������ƥ���׺���ȱ�O(m)
   int m = strlen(P); int* SS = new int[m];  //Suffix Size��
   SS[m - 1]  =  m; //�����һ���ַ����ԣ���֮ƥ������׺��������P��
// ���£��ӵ����ڶ����ַ�����������ɨ��P�����μ����SS[]�������
   for (int lo = m - 1, hi = m - 1, j = lo - 1; j >= 0; j --)
      if ((lo < j) && (SS[m - hi + j - 1] <= j - lo)) //���һ
         SS[j] =  SS[m - hi + j - 1]; //ֱ�����ô�ǰ�Ѽ������SS[]
      else { //�����
         hi = j; lo = __min(lo, hi);
         while ((0 <= lo) && (P[lo] == P[m - hi + lo - 1])) //����ѭ����
            lo--; //����Աȴ���(lo, hi]ǰ�˵��ַ�
         SS[j] = hi - lo;
      }
   /*DSA*/printf("-- SS[] Table -------\n");
   /*DSA*/for (int i = 0; i < m; i ++) printf("%4d", i); printf("\n");
   /*DSA*/printString(P); printf("\n");
   /*DSA*/for (int i = 0; i < m; i ++) printf("%4d", SS[i]); printf("\n\n");
   return SS;
}

int* buildGS(char* P) { //����ú�׺λ������O(m)
   int* SS = buildSS(P); //Suffix Size table
   size_t m = strlen(P); int* GS = new int[m]; //Good Suffix shift table
   for (size_t j = 0; j < m; j ++) GS[j] = m; //��ʼ��
   for (size_t i = 0, j = m - 1; j < UINT_MAX; j --) //������һɨ����ַ�P[j]
      if (j + 1 == SS[j]) //��P[0, j] = P[m-j-1, m)����
         while (i < m - j - 1) //����P[m-j-1]����ÿ���ַ�P[i]���ԣ�����ѭ������
            GS[i++] = m - j - 1; //m-j-1����GS[i]��һ��ѡ��
   for (size_t j = 0; j < m - 1; j ++) //����ɨ����ַ�P[j]���������㷨��GS[j]���ϵݼ���ֱ����С
      GS[m - SS[j] - 1] = m - j - 1; //m-j-1������GS[m-SS[j]-1]ֵ��һ��ѡ��
   /*DSA*/printGS(P, GS);
   delete [] SS; return GS;
}
