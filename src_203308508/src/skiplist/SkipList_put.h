/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::put(K k, V v) { //��ת����������㷨
   Entry<K, V>* e = new Entry<K, V>(k, v);
   if (empty()) insertAsFirst(new Quadlist<Entry<K, V>*>); //�����׸�Entry
   ListNode<Quadlist<Entry<K, V>*>*>* qlist = first(); //�Ӷ����б��
   QuadlistNode<Entry<K, V>*>* p = qlist->data->first();; //�׽ڵ㿪ʼ����
   if (skipSearch(qlist, p, k)) //�����ʵ��Ĳ���λ��
      while (p->below) p = p->below; //��������ͬ����������ǿ��ת������
   qlist = last(); //���£�������p���Ҳ࣬һ���������Ե׶����������
   QuadlistNode<Entry<K, V>*>* b
      = qlist->data->insertAfterAbove(e, p); //��e������p�Ҳࣨ��Ϊ�����Ļ�����
   while (rand() % 2) { //��Ͷ��Ӳ�ң���ȷ��������Ҫ�ٳ���һ�㣬��
      while (qlist->data->valid(p) && !p->above) p = p->pred; //�ҳ������ڴ˸߶ȵ����ǰ��
      if (!qlist->data->valid(p)) { //����ǰ����header
         if (qlist == first()) //�ҵ�ǰ������㣬����ζ�ű���
            insertAsFirst(new Quadlist<Entry<K, V>*>); //���ȴ����µ�һ�㣬Ȼ��
         p = qlist->pred->data->first()->pred; //��pת����һ��Skiplist��header
      } else //���򣬿ɾ���
         p = p->above; //��p�������ø߶�
      qlist = qlist->pred; //����һ�㣬���ڸò�
      b = qlist->data->insertAfterAbove(e, p, b); //���½ڵ����p֮��b֮��
   }//�κ󣺵�������������۲������ߵ���Ӧ�仯
   return true; //Dictionary�����ظ�Ԫ�أ��ʲ���سɹ���������Hashtable��Map���в���
}