/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include <iostream>
/*DSA*/using namespace std;

void shuffle(int A[], int n) { //��A[0, n)�������
   while (1 < n)
      swap(A[rand() % n], A[--n]);
}

void shuffle(int A[], int lo, int hi) //��A[lo, hi)�������
{  shuffle(A + lo, hi - lo);  }
