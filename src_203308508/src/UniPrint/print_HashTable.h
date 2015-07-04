/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Hashtable
 ******************************************************************************************/

template <typename K, typename V> //e��value�ͱȽ���
void UniPrint::p(Hashtable<K, V>& ht) { //����
   printf("%s*%d/%d:\n", typeid(ht).name(), ht.N, ht.M); //������Ϣ
   for (int i = 0; i < ht.M; i++) //���Ͱ���
      printf("  %4d  ", i);
   printf("\n");
   for (int i = 0; i < ht.M; i++) //�������Ԫ��
      if (ht.ht[i]) printf("-<%04d>-", ht.ht[i]->key); //��ʾ�ã���������int
      else if (ht.lazyRemoval->test(i)) printf("-<xxxx>-");
      else printf("--------");
   printf("\n");
   for (int i = 0; i < ht.M; i++) //�������Ԫ��
      if (ht.ht[i]) printf("    %c   ", ht.ht[i]->value); //��ʾ�ã���������char
//      if (ht.ht[i]) printf("%8s", ht.ht[i]->value); //���Huffman������ʹ�õ�ɢ�б�
      else if (ht.lazyRemoval->test(i)) printf(" <xxxx> ");
      else printf("        ");
   printf("\n");
}
