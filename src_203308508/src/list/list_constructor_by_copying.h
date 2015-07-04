/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //assert: pΪ�Ϸ�λ�ã���������n-1����̽ڵ�
List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p, n); } //�����б�����λ��p���n��

template <typename T>
List<T>::List(List<T> const & L) { copyNodes(L.first(), L._size); } //���帴���б�L

template <typename T> //assert: r+n <= L._size
List<T>::List(List<T> const & L, int r, int n) { copyNodes(L[r], n); } //����L���Ե�r�����n��