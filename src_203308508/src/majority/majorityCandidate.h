/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T majEleCandidate(Vector<T> A) { //选出具备必要条件的主流数候选者
   T maj; //主流数候选者
// 线性扫描，并借助计数器c，记录主流数候选者与其它元素的数量差额
   for (int c = 0, i = 0; i < A.size(); i++)
      if (0 == c) { //若c归零，则意味着此时的前缀P可剪除
         maj = A[i]; c = 1; //主流数候选者改为新的当前元素
      } else //否则
         (maj == A[i]) ? c++ : c--; //相应地更新差额计数器
      return maj; //至此，原向量的主流数若存在，则只能是maj —— 尽管反之不然

}