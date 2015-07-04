/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 当试图对空的优先队列应用getMin()或delMin()方法时，本意外将被抛出
 */

package dsa;

public class ExceptionPQueueEmpty extends RuntimeException {
   public ExceptionPQueueEmpty(String err) {
      super(err);
   }
}
