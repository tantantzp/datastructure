/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of stack
 ******************************************************************************************/
#include "stack_test.h"

int testID = 0; //���Ա��

/******************************************************************************************
 * ����ջ
 ******************************************************************************************/
template <typename T> //Ԫ������
void testStack(int n) {
   Stack<T> S;
   printf("\n  ==== Test %2d. Growing stack\n", testID++);
   while (S.size() < n) {
      T e = rand() % (T)2*n;
      if (S.empty() || (30 < (rand() % 100))) { //70%������ջ
         printf("pushing "); print(e); printf(" ...\n");
         S.push(e);
      } else { //30%���ʳ�ջ
         printf("poping with ... "); print(S.pop()); printf("\n");
      }
      print(S);
   }
   printf("\n  ==== Test %2d. Shrinking stack\n", testID++);
   while (!S.empty()) {
      T e = dice((T)2*n);
      if (70 < dice(100)) { //70%������ջ
         printf("pushing "); print(e); printf(" ...\n");
         S.push(e);
      } else { //70%���ʳ�ջ
         printf("poping with ... "); print(S.pop()); printf("\n");
      }
      print(S);
   }
}


/******************************************************************************************
 * ����ջ
 ******************************************************************************************/
int main(int argc, char* argv[]) {
   if (2 > argc) { printf("Usage: %s <size of test>\a\a\n", argv[0]); return 1; }
   srand((unsigned int)time(NULL)); //�����������
   testStack<int>(atoi(argv[1])); //Ԫ�����͡��Ƚ�����������������ѡ��

   return 0;
}