/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color)) //�ⲿ�ڵ�Ҳ�����ڽڵ�
#define IsRed(p) (!IsBlack(p)) //�Ǻڼ���
#define BlackHeightUpdated(x) ( \
   (stature((x).lChild) == stature((x).rChild)) && \
   ((x).height == (IsRed(&x) ? stature((x).lChild) : stature((x).lChild) + 1)) \
) //RedBlack�߶ȸ�������