/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * �����Һ�����ȡ�����ߣ����ȸߣ����븸��pͬ��������
 * ��AVLƽ�����ǰ�����ȷ���ع�����
 ******************************************************************************************/
#define tallerChild(x) ( \
   stature((x)->lChild) > stature((x)->rChild) ? (x)->lChild : ( \
   stature((x)->rChild) > stature((x)->lChild) ? (x)->rChild : ( \
   IsLChild(*(x)) ? (x)->lChild : (x)->rChild \
   ) \
   ) \
)
