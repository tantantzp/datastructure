/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> template <typename PU> //�������͡������͡����ȼ�������
void Graph<Tv, Te>::pfs(int s, PU prioUpdater) { //���ȼ������㷨���
   reset(); priority(s) = 0; status(s) = VISITED; parent(s) = -1; //��ʼ�������s���������
   for (int i = 1; i < n; i++) { //��������n-1�������n-1����
      for (int w = firstNbr(s); -1 < w; w = nextNbr(s, w)) //ö��s�������ھ�w
         prioUpdater(this, s, w); //���¶���w�����ȼ����丸����
      for (int shortest = INT_MAX, w = 0; w < n; w++)
         if (status(w) == UNDISCOVERED) //����δ����������Ķ�����
            if (shortest > priority(w)) //ѡ����һ��
               { shortest = priority(w); s = w; } //���ȼ���ߵĶ���s
      status(s) = VISITED; status(parent(s), s) = TREE; //��s�����븸��������߼��������
   }
} //ͨ�������������ȼ����²���prioUpdater������ʵ�ֲ�ͬ���㷨����
