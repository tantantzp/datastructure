/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ����ͼ��������Ӧ��enqueue����ʱ�������⽫���׳�
 */

package dsa;

public class ExceptionQueueFull extends RuntimeException {
   public ExceptionQueueFull(String err) {
      super(err);
   }
}
