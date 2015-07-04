/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int RedBlack<T>::updateHeight(BinNodePosi(T) x) { //更新红黑树节点高度
   x->height = max(stature(x->lChild), stature(x->rChild)); //孩子一般黑高度相等，除非出现双黑时
/*DSA*/// 红黑树中各节点左、右孩子的黑高度通常相等
/*DSA*/// 这里之所以取更大值，是便于在删除节点后的平衡调整过程中，正确更新被删除节点父亲的黑高度
/*DSA*/// 否则，rotateAt()会根据被删除节点的替代者（高度小一）设置父节点的黑高度
   return IsBlack(x) ? x->height++ : x->height; //若当前节点为黑，则计入黑深度
} //BinNode创建时默认高度取0，故所有节点的黑高度比原定义少一，好在不致影响到各种算法中的比较判断
