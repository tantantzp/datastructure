/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> struct DijkstraPU { //���Dijkstra�㷨�Ķ������ȼ�������
   virtual void operator()(Graph<Tv, Te>* g, int uk, int v) {
      if (g->status(v) == UNDISCOVERED) //����ukÿһ��δ�����ֵ��ڽӶ���v
         if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) //��Dijkstra�������ɳ�
            { g->priority(v) = g->priority(uk) + g->weight(uk, v); g->parent(v) = uk; }
   }
};