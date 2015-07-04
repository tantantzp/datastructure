/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�����б�Ĺ鲢����ǰ�б�����p���n��Ԫ�أ����б�L����q���m��Ԫ�ع鲢
void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m) {
// assert:  this.valid(p) && rank(p) + n <= size && this.sorted(p, n)
//          L.valid(q) && rank(q) + m <= L._size && L.sorted(q, m)
// ע�⣺�ڹ鲢����֮��ĳ��ϣ��п��� this == L && rank(p)+n = rank(q)
   ListNodePosi(T) pp = p->pred; //����ǰ����������header�����Ա㷵��ǰ ...
   while (0 < m) //��q��δ�Ƴ�����֮ǰ
      if ((0 < n) && (p->data <= q->data)) //��p������������v(p) <= v(q)����
         { if (q == (p = p->succ)) break; n--; } //��pֱ�Ӻ���
      else //��p�ѳ����ҽ��v(q) < v(p)����
         { insertBefore(p, L.remove((q = q->succ)->pred)); m--; } //��q����p֮ǰ
   p = pp->succ; //ȷ���鲢������ģ��£����
}