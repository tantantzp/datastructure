/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"
float calcu(float a, char op, float b) { //ִ�ж�Ԫ����
   switch (op) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if (0==b) exit(-1); return a/b; //ע�⣺����и�����Ϊ����ܲ���ȫ
      case '^' : return pow(a, b);
      default  : exit(-1);
   }
}

float calcu(char op, float b) { //ִ��һԪ����
   switch (op) {
      case '!' : return (float)facI((int)b); //Ŀǰ���н׳ˣ����մ˷�ʽ���
      default  : exit(-1);
   }
}