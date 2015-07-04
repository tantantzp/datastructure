/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 当作为参数的数组下标、向量的秩或列表的位置越界时，本意外将被抛出
 */

package dsa;

public class ExceptionBoundaryViolation extends RuntimeException {
   public ExceptionBoundaryViolation(String err) {
      super(err);
   }
}
