/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //基于DFS的拓扑排序算法
Stack<Tv>* Graph<Tv, Te>::tSort(int s) { //assert: 0 <= s < n
   reset(); int clock = 0; int v = s;
   Stack<Tv>* S = new Stack<Tv>; //用栈记录排序顶点
   do {
      if (UNDISCOVERED == status(v))
         if (!TSort(v, clock, S)) { //clock不是必需
            /*DSA*/print(S);
            while (!S->empty()) S->pop(); break; //任一连通域（亦即整图）非DAG，则直接返回
         }
   } while (s != (v = (++v % n)));
   return S; //若输入为DAG，则S内各顶点自顶向底排序；否则（不存在拓扑排序），S空
}

template <typename Tv, typename Te> //基于DFS的拓扑排序算法（单趟）
bool Graph<Tv, Te>::TSort(int v, int& clock, Stack<Tv>* S) { //assert: 0 <= v < n
   dTime(v) = ++clock; status(v) = DISCOVERED; //发现顶点v
   for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //枚举v的所有邻居u
      switch (status(u)) { //并视u的状态分别处理
         case UNDISCOVERED:
            parent(u) = v; status(v, u) = TREE;
            if (!TSort(u, clock, S)) return false; //从顶点u处深入
            break;
         case DISCOVERED:
            status(v, u) = BACKWARD; //一旦发现后向边（非DAG），则
            return false; //退出而不再深入
         default: //VISITED (digraphs only)
            status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
            break;
      }
   status(v) = VISITED; S->push(vertex(v)); //顶点被标记为VISITED时入栈
   return true;
}