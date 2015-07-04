/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T, typename VST> //Ԫ�����͡�������
void travPost_R(BinNodePosi(T) x, VST& visit) { //��������������㷨���ݹ�棩
   if (!x) return;
   travPost_R(x->lChild, visit);
   travPost_R(x->rChild, visit);
   visit(x->data);
}
