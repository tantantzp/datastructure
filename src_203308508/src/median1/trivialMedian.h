/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

// ��λ���㷨�����棺Ч�ʵͣ���������max(n1, n2)��С�����
template <typename T> //������S1[lo1, lo1+n1)��S2[lo2, lo2+n2)�ֱ���������������ظ�
T trivialMedian(Vector<T>& S1, int lo1, int n1, Vector<T>& S2, int lo2, int n2) {
   /*DSA*/printf("trivial median\n");
   Vector<T> S; int i1 = 0, i2 = 0; /*DSA*/print(S);
   while ((i1 < n1) && (i2 < n2)) {
      while ((i1 < n1) && S1[lo1 + i1] <= S2[lo2 + i2]) S.insert(S.size(), S1[lo1 + i1++]);
      while ((i2 < n2) && S2[lo2 + i2] <= S1[lo1 + i1]) S.insert(S.size(), S2[lo2 + i2++]);
   }
   while (i1 < n1) S.insert(S.size(), S1[lo1 + i1++]);
   while (i2 < n2) S.insert(S.size(), S1[lo2 + i2++]);
   return S[(n1+n2)/2];
}