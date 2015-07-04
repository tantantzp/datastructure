/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../prime/primeNLT.h"

template <typename K, typename V> Hashtable<K, V>::Hashtable(int c) { //����������С��c��ɢ�б�
   M = primeNLT(c, 1048576, "../../_input/prime-1048576-bitmap.txt");
      //�Բ�С��2*N������Ϊ����
   N = 0; ht = new Entry<K, V>*[M]; //����Ͱ���飬��֤װ�����Ӳ�����50%
   memset(ht, 0, sizeof(Entry<K, V>*)*M); //��ʼ����Ͱ
   lazyRemoval = new Bitmap(M); //����ɾ����Ǳ���ͼ
   //*DSA*/printf("A bucket array has been created with capacity = %d\n\n", M);
}