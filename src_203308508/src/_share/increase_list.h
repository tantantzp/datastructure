/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "..\list\list.h"

template <typename T> void increase(List<T> & L) //ͳһ�����б��еĸ�Ԫ��
{  L.traverse(Increase<T>());  } //��Increase<T>()Ϊ�����������б���