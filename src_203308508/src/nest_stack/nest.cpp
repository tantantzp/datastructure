/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "nest.h"

bool paren(const char exp[], int lo, int hi) { //���ʽ����ƥ���飬�ɼ����������
   Stack<char> S; //ʹ��ջ��¼�ѷ��ֵ���δƥ���������
   for (int i = 0; exp[i]; i++) /* ��һ��鵱ǰ�ַ� */ /*DSA*/ {
      switch (exp[i]) { //������ֱ�ӽ�ջ������������ջ��ʧ�䣬����ʽ�ز�ƥ��
         case '(': case '[': case '{': S.push(exp[i]); break;
         case ')': if ((S.empty()) || ('(' != S.pop())) return false; break; 
         case ']': if ((S.empty()) || ('[' != S.pop())) return false; break;
         case '}': if ((S.empty()) || ('{' != S.pop())) return false; break;
         default: break; //�������ַ�һ�ɺ���
      } /*DSA*/displayProgress(exp, i, S); }
   return S.empty(); //�������ʽɨ�����ջ�����Բ����������ţ���ƥ�䣻����ջ�գ�ƥ��
}