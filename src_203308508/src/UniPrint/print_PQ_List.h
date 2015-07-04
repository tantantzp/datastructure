/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��ӡ���PQ_List
 ******************************************************************************************/
template <typename T> //Ԫ������
void UniPrint::p(PQ_List<T> & pq) { //����
   printf("%s*%d:\n", typeid(pq).name(), pq.size()); //������Ϣ
   print(pq.list); printf("\n");
}
