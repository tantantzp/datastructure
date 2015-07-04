/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * Comparable对象的默认比较器
 */

package dsa;

public class ComparatorDefault implements Comparator {
   public ComparatorDefault() {}
   public int compare(Object a, Object b) throws ClassCastException {
      return ((Comparable) a).compareTo(b);
   }
}