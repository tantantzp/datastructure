/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool majority(Vector<T> A, T& maj) { //�����������㷨��T�ɱȽϿ��е�
   maj = majEleCandidate(A); //��Ҫ�ԣ�ѡ����ѡ��maj
   return majEleCheck(A, maj); //����ԣ���֤maj�Ƿ��ȷ��ѡ
}