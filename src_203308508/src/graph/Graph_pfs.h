/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> template <typename PU> //顶点类型、边类型、优先级更新器
void Graph<Tv, Te>::pfs(int s, PU prioUpdater) { //优先级搜索算法框架
   reset(); priority(s) = 0; status(s) = VISITED; parent(s) = -1; //初始化，起点s加入遍历树
   for (int i = 1; i < n; i++) { //依次引入n-1个顶点和n-1条边
      for (int w = firstNbr(s); -1 < w; w = nextNbr(s, w)) //枚举s的所有邻居w
         prioUpdater(this, s, w); //更新顶点w的优先级及其父顶点
      for (int shortest = INT_MAX, w = 0; w < n; w++)
         if (status(w) == UNDISCOVERED) //从尚未加入遍历树的顶点中
            if (shortest > priority(w)) //选出下一个
               { shortest = priority(w); s = w; } //优先级最高的顶点s
      status(s) = VISITED; status(parent(s), s) = TREE; //将s及其与父顶点的联边加入遍历树
   }
} //通过定义具体的优先级更新策略prioUpdater，即可实现不同的算法功能
