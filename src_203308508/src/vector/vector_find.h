/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo - 1
Rank Vector<T>::find(T const & e, Rank lo, Rank hi) const { //assert: 0 <= lo < hi <= _size
   while ((lo < hi--) && (_elem[hi] != e)); //�Ӻ���ǰ��˳�����
   return hi; //��hi < lo������ζ��ʧ�ܣ�����hi������Ԫ�ص���
}