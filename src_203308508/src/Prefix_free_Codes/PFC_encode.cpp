/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "PFC.h"

int encode(PFCTable* table, Bitmap& codeString, char* s) { //PFC�����㷨
   int n = 0;
   for (size_t m = strlen(s), i = 0; i < m; i++) { //��������s[]�е�ÿ���ַ�
      char** pCharCode = table->get(s[i]); //ȡ�����Ӧ�ı��봮
      if (!pCharCode) pCharCode = table->get(s[i]+'A'-'a'); //Сд��ĸתΪ��д
      if (!pCharCode) pCharCode = table->get(' '); //�޷�ʶ����ַ�ͳһ�����ո�
      printf("%s", *pCharCode); //�����ǰ�ַ��ı���
      for (size_t m = strlen(*pCharCode), j = 0; j < m; j++) //����ǰ�ַ��ı��������봮
         '1' == *(*pCharCode+j) ? codeString.set(n++) : codeString.clear(n++);
   }
   /*DSA*/printf("\n");
   return n; //�����Ʊ��봮��¼��codeString�У����ر��봮�ܳ�
}
