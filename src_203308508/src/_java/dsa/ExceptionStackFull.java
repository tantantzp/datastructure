/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 当试图对满栈应用push方法时，本意外将被抛出
 */

package dsa;

public class ExceptionStackFull extends RuntimeException {
   public ExceptionStackFull(String err) {
      super(err);
   }
}
