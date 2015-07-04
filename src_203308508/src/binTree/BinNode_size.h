/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int BinNode<T>::size() { //统计当前节点后代总数，即以其为根的子树规模
  int s = 1; //计入本身
  if (lChild) s += lChild->size(); //递归计入左子树规模
  if (rChild) s += rChild->size(); //递归计入右子树规模
  return s;
}