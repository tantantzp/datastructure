/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

__int64 fibI(int n) { //����Fibonacci���еĵ�n������棩��O(n)
   __int64 f = 1, g = 0; //��ʼ����fib(1)=1, fib(0)=0
   while (0 < n--) { f = f + g; g = f - g; } //����ԭʼ���壬ͨ��n�μӷ��ͼ�������fib(n)
   return g; //����
}