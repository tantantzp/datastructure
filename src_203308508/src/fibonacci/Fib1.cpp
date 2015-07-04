/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 fib(int n) { //����Fibonacci���еĵ�n����ֵݹ�棩��O(2^n)
   return (2 > n) ?
            (__int64)n //������ݹ����ֱ��ȡֵ
          : fib(n-1) + fib(n-2); //���򣬵ݹ����ǰ�����ͼ�Ϊ����
}