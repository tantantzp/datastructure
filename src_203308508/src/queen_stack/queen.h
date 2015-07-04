/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

struct Queen { //�ʺ���
   int x, y; //�ʺ��������ϵ�λ������
   Queen(int xx = 0, int yy = 0) : x(xx), y(yy) {};
   bool operator==(Queen const & q) { //�����еȲ��������Լ�ⲻͬ�ʺ�֮����ܵĳ�ͻ
      return    (x == q.x) //�г�ͻ����һ�����ʵ�����ᷢ������ʡ�ԣ�
             || (y == q.y) //�г�ͻ
             || (x + y == q.x + q.y) //�����Խ��߳�ͻ
             || (x - y == q.x - q.y); //�ط��Խ��߳�ͻ
   }
   bool operator!=(Queen const & q) { return !(*this == q); } //���ز��Ȳ����� /*DSA*/�ɷ�д�ɣ�return *this != q��
};