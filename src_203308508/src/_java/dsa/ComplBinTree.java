/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ��ȫ�������ӿ�
 */

package dsa;

public interface ComplBinTree extends BinTree {
   //���ɲ�����һ�����e���ⲿ�ڵ㣬�ýڵ��Ϊ�µ�ĩ�ڵ�
   public BinTreePosition addLast(Object e);

   //ɾ��ĩ�ڵ㣬���������д�ŵ�����
   public Object delLast();

   //���ذ��ղ�α������Ϊi�Ľڵ��λ�ã�0 <= i < size()
   public BinTreePosition posOfNode(int i);
}