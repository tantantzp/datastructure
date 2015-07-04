/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 默认判等器
 */

package dsa;

public class EqualityTesterDefault implements EqualityTester {
   public EqualityTesterDefault() {}
   public boolean isEqualTo(Object a, Object b)
   {  return (a.equals(b)); }//使用Java提供的判等器
}