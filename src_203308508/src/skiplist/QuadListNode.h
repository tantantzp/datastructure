/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "../Entry/Entry.h"
#define QuadlistNodePosi(T)  QuadlistNode<T>* //跳转表节点位置
template <typename T> class QuadlistNode{ //QuadlistNode模板类
public:
// 成员
   T entry; //数值
   QuadlistNodePosi(T) pred;  QuadlistNodePosi(T) succ;  //前驱、后继
   QuadlistNodePosi(T) above; QuadlistNodePosi(T) below; //上邻、下邻
// 构造函数
   QuadlistNode() {} //针对header和trailer的构造
   QuadlistNode //默认构造器
      ( T e, QuadlistNodePosi(T) p = NULL, QuadlistNodePosi(T) s = NULL,
      QuadlistNodePosi(T) a = NULL, QuadlistNodePosi(T) b = NULL)
      : entry(e), pred(p), succ(s), above(a), below(b) {}
// 操作接口
   QuadlistNodePosi(T) insertAsSuccAbove //插入新节点，以当前节点为前驱，以节点b为下邻
      (T const & e, QuadlistNodePosi(T) b = NULL);
};

#include "QuadlistNode_implementation.h"