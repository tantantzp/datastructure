/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //��㹹���㷨��ͨ������Ԫ��λ�ù�������[lo,hi]����㣬����������
Rank Vector<T>::partition(Rank lo, Rank hi) { //�汾A��������ʽ
   swap(_elem[lo], _elem[lo + rand() % (hi-lo+1)]); //��ѡһ��Ԫ������Ԫ�ؽ���
   T pivot = _elem[lo]; //����Ԫ��Ϊ��ѡ��㡪�������Ͻ�������Ч�����ѡȡ
   while (lo < hi) { //�����������˽�������м�ɨ��
      while ((lo < hi) && (pivot <= _elem[hi])) //�ڲ�С��pivot��ǰ����
         hi--; //������չ�Ҷ�������
      _elem[lo] = _elem[hi]; //С��pivot�߹������������
      while ((lo < hi) && (_elem[lo] <= pivot)) //�ڲ�����pivot��ǰ����
         lo++; //������չ���������
      _elem[hi] = _elem[lo]; //����pivot�߹����Ҳ�������
   } //assert: lo == hi
   _elem[lo] = pivot; //�����ݵ�����¼����ǰ����������֮��
   return lo; //����������
}