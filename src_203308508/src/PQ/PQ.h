/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> class PQ { //优先级队列PQ模板类
public:
   virtual int size() = 0; //查询当前规模
   bool empty() { return !size(); } //判断队列是否为空
   virtual void insert(T) = 0; //按照比较器确定的优先级次序插入词条
   virtual T getMax() = 0; //取出优先级最高的词条
   virtual T delMax() = 0; //删除优先级最高的词条
};