/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool majority(Vector<T> A, T& maj) { //主流数查找算法：T可比较可判等
   maj = majEleCandidate(A); //必要性：选出候选者maj
   return majEleCheck(A, maj); //充分性：验证maj是否的确当选
}