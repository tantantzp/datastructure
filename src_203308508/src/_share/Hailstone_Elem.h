/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct Hailstone { //�������󣺰���Hailstone����ת��һ��T�����
   virtual void operator()(T& e) { //����T��ֱ������������
      int step = 0; //ת�����貽��
      while (1 != e) { //���桢ż��ת����ֱ��Ϊ1
         (e % 2) ? e = 3*e+1 : e /= 2;
         step++;
      }
      e = step; //����ת����������
   }
};