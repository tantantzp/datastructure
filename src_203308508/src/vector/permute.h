/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void permute(Vector<T>& V) { //�������������ʹ��Ԫ�صȸ��ʳ�����ÿһλ��
   for (int i = V.size(); i > 0; i--) //�Ժ���ǰ
      swap(V[i-1], V[rand() % i]); //V[i-1]��V[0, i-1]��ĳһ���Ԫ�ؽ���
}