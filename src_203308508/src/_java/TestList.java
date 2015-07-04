/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * �����б�
 */
import dsa.*;
import java.io.*;

public class TestList {
   static final int TEST_SIZE = 31;
   public static void main(String[] args) {
      List list = new List_DLNode();
      while (TEST_SIZE > list.getSize()) {
         double dice = Math.random();
         if (0.35 < dice)
            list.insertFirst(new Integer((int)(Math.random()*(4 * TEST_SIZE))));
         else if (!list.isEmpty())
            list.removeLast();
         Print(list);
      }
   }

   //����б��е�����Ԫ��
   protected static void Print(List list) {
      Iterator it = list.elements();
      while (it.hasNext())
         System.out.print(it.getNext() + " ");
      System.out.println();
   }

}