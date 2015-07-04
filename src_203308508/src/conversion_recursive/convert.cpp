/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "../conversion/convert.h"

void convert(Stack<char>& S, __int64 n, int base) { //ʮ������n��base���Ƶ�ת�����ݹ�棩
   static char digit[] //0 < n, 1 < base <= 16���½����µ���λ���ţ�����baseȡֵ��Χ�ʵ�����
   = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
   if (0 < n) { //����������֮ǰ������
      convert(S, n/base, base); //ͨ���ݹ�õ����и���λ
      S.push(digit[n % base]); //�����λ
   }
} //�½������ɸߵ��͵ĸ���λ���Զ����±�����ջS��