/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "..\vector\vector.h"

template <typename T> void increase(Vector<T> & V) //ͳһ���������еĸ�Ԫ��
{  V.traverse(Increase<T>());  } //��Increase<T>()Ϊ�����������б���