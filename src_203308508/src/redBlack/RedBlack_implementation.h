/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
* 将BST各方法的实现部分，简洁地引入BST.h
* 效果等同于将这些实现直接汇入BST.h
* 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
******************************************************************************************/
#include "RedBlack_insert.h" //插入
#include "RedBlack_remove.h" //删除
#include "RedBlack_updateHeight.h" //更新高度
#include "RedBlack_solveDoubleRed.h" //双红修正
#include "RedBlack_solveDoubleBlack.h" //双黑修正
