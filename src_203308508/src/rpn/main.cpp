/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

char* removeSpace(char* s) { //�޳�s[]�еİ׿ո�
   char *p=s, *q=s;
   while (true) {
      while (isspace(*q)) q++;
      if ('\0' == *q) { *p = '\0'; return s; }
      *p++ = *q++;
   }
}

int main(int argc, char* argv[]) { //����ʽ��ֵ����ڣ�
   for (int i=1; i<argc; i++) { //��һ�����������в���������ʽ��
                                                      /*DSA*/system("cls"); printf("\nPress any key to evaluate: [%s]\a\n", argv[i]); getchar();
      char* rpn = (char*)malloc(sizeof(char)*1);   rpn[0] = '\0'; //�沨������ʽ
      float value = evaluate(removeSpace(argv[i]), rpn); //��ֵ
                                                      /*DSA*/printf("EXPR\t: %s\n", argv[i]); //���ԭ����ʽ
                                                      /*DSA*/printf("RPN\t: [ %s]\n", rpn); //���RPN
                                                      /*DSA*/printf("Value\t= %.1f = %d\n", value, (int)value); //�������ʽ��ֵ
      free(rpn);   rpn = NULL;
                                                      /*DSA*/getchar();
   }
   return 0;
}