/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 比较器接口
 */

package dsa;

public interface Comparator {
   public int compare(Object a, Object b);//若a>（=或<）b，返回正数、零或负数
}