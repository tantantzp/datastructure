/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 判等器接口
 */

package dsa;

public interface EqualityTester {
   public boolean isEqualTo(Object a, Object b);//若a与b相等，则返回true；否则，返回false
}