/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 当试图对空树进行操作时，本意外将被抛出
 */

package dsa;

public class ExceptionTreeEmpty extends RuntimeException {
   public ExceptionTreeEmpty(String err) {
      super(err);
   }
}
