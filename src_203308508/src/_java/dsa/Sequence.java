/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 序列接口
 */

package dsa;

public interface Sequence extends Vector, List {
   //若0 <= r < getSize()，则返回秩为r的元素所在的位置；否则，报错
   public Position rank2Pos(int r)
   throws ExceptionBoundaryViolation;

   //若p是序列中的合法位置，则返回存放于p处的元素的秩；否则，报错
   public int pos2Rank(Position p)
   throws ExceptionPositionInvalid;
}