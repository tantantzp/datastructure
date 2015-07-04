/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //删除Quadlist内位置p处的节点，返回被删除节点的数值
T Quadlist<T>::remove(QuadlistNodePosi(T) p) { //assert: p为Quadlist中的合法位置
   T e = p->entry; //备份待删除词条
   p->pred->succ = p->succ; p->succ->pred = p->pred; //摘除节点
   release(p); _size--; //约定：p->data交由程序员另行释放
   return e; //返回被删除节点的数值
}

template <typename T> int Quadlist<T>::clear() { //清空Quadlist
   int oldSize = _size;
   while (0 < _size) remove(header->succ); //逐个删除所有节点
   return oldSize;
}