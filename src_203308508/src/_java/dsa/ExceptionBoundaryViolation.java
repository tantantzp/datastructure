/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ����Ϊ�����������±ꡢ�������Ȼ��б��λ��Խ��ʱ�������⽫���׳�
 */

package dsa;

public class ExceptionBoundaryViolation extends RuntimeException {
   public ExceptionBoundaryViolation(String err) {
      super(err);
   }
}
