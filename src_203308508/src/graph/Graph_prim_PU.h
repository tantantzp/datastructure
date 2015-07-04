/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> struct PrimPU { //针对Prim算法的顶点优先级更新器
   virtual void operator()(Graph<Tv, Te>* g, int uk, int v) {
      if (g->status(v) == UNDISCOVERED) //对于uk每一尚未被发现的邻接顶点v
         if (g->priority(v) > g->weight(uk, v)) //按Prim策略做松弛
            { g->priority(v) = g->weight(uk, v); g->parent(v) = uk; }
   }
};