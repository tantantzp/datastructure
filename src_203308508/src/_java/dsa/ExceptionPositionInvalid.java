/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 当作为参数的数组下标、向量的秩或列表的位置非法时，本意外将被抛出
 */

package dsa;

public class ExceptionPositionInvalid extends RuntimeException {
   public ExceptionPositionInvalid(String err) {
      super(err);
   }
}
