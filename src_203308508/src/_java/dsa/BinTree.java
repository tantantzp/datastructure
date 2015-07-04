/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * �������ӿ�
 */

package dsa;

public interface BinTree {
   //��������
   public BinTreePosition getRoot();

   //�ж��Ƿ�����
   public boolean isEmpty();

   //�������Ĺ�ģ���������ĺ����Ŀ��
   public int getSize();

   //�������������ĸ߶�
   public int getHeight();

   //ǰ�����
   public Iterator elementsPreorder();

   //�������
   public Iterator elementsInorder();

   //�������
   public Iterator elementsPostorder();

   //��α���
   public Iterator elementsLevelorder();
}