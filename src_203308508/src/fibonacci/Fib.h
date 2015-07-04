/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

class Fib { //Fibonacci数列类
private:
   int f, g; //f = fib(k-1), g = fib(k+1)
public:
   Fib(int n) //初始化为不小于n的最小Fibonacci项。比如Fib(6)将初始化为8
      { f = 0; g = 1; while (g < n) next(); } //O(log_phi(n))时间
   int get() //获取当前Fibonacci项（如，若当前为8，则返回8）
      { return g; } //O(1)时间
   int next() //转至下一Fibonacci项（如，若当前为8，则转至13）
      { g += f = g - f; return g; } //O(1)时间
   int prev() //转至上一Fibonacci项（如，若当前为8，则转至5）
      { f = (g -= f) - f; return g; } //O(1)时间
};