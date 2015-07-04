/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ���нӿ�
 */

package dsa;

public interface Sequence extends Vector, List {
   //��0 <= r < getSize()���򷵻���Ϊr��Ԫ�����ڵ�λ�ã����򣬱���
   public Position rank2Pos(int r)
   throws ExceptionBoundaryViolation;

   //��p�������еĺϷ�λ�ã��򷵻ش����p����Ԫ�ص��ȣ����򣬱���
   public int pos2Rank(Position p)
   throws ExceptionPositionInvalid;
}