/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ˫�˶��нӿ�
 */

package dsa;

public interface Deque {
   public int getSize();//���ض�����Ԫ����Ŀ
   public boolean isEmpty();//�ж϶����Ƿ�Ϊ��
   public Object first() throws ExceptionQueueEmpty;//ȡ��Ԫ�أ�����ɾ����
   public Object last() throws ExceptionQueueEmpty;//ȡĩԪ�أ�����ɾ����
   public void insertFirst(Object obj);//����Ԫ����Ϊ��Ԫ�ز���
   public void insertLast(Object obj);//����Ԫ����ΪĩԪ�ز���
   public Object removeFirst() throws ExceptionQueueEmpty;//ɾ����Ԫ��
   public Object removeLast() throws ExceptionQueueEmpty;//ɾ��ĩԪ��
   public void Traversal();//����
}