/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

class Fib { //Fibonacci������
private:
   int f, g; //f = fib(k-1), g = fib(k+1)
public:
   Fib(int n) //��ʼ��Ϊ��С��n����СFibonacci�����Fib(6)����ʼ��Ϊ8
      { f = 0; g = 1; while (g < n) next(); } //O(log_phi(n))ʱ��
   int get() //��ȡ��ǰFibonacci��磬����ǰΪ8���򷵻�8��
      { return g; } //O(1)ʱ��
   int next() //ת����һFibonacci��磬����ǰΪ8����ת��13��
      { g += f = g - f; return g; } //O(1)ʱ��
   int prev() //ת����һFibonacci��磬����ǰΪ8����ת��5��
      { f = (g -= f) - f; return g; } //O(1)ʱ��
};