/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * �����б�ʵ�ֵ�Ԫ�ص�����
 */

package dsa;

public class IteratorElement implements Iterator {
   private List list;//�б�
   private Position nextPosition;//��ǰ����һ����Ԫ�ص�λ��

   //Ĭ�Ϲ��췽��
   public IteratorElement() { list = null; }

   //���췽��
   public IteratorElement(List L) {
      list = L;
      if (list.isEmpty())//���б�Ϊ�գ���
         nextPosition = null;//��ǰԪ���ÿ�
      else//����
         nextPosition = list.first();//�ӵ�һ��Ԫ�ؿ�ʼ
   }

   //�����������Ƿ���ʣ���Ԫ��
   public boolean hasNext() { return (null != nextPosition); }

   //���ص������е���һԪ��
   public Object getNext() throws ExceptionNoSuchElement {
      if (!hasNext()) throw new ExceptionNoSuchElement("���⣺û����һԪ��");
      Position currentPosition = nextPosition;
      if (currentPosition == list.last())//���ѵ���βԪ�أ���
         nextPosition = null;//��������һԪ��
      else//����
         nextPosition = list.getNext(currentPosition);//ת����һԪ��
      return currentPosition.getElem();
   }
}