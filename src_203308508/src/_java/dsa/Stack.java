/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * 栈接口
 */

package dsa;

public interface Stack {
   public int getSize();//返回栈中元素数目
   public boolean isEmpty();//判断栈是否为空
   public Object top() throws ExceptionStackEmpty;//取栈顶元素（但不删除）
   public void push (Object ele);//入栈
   public Object pop() throws ExceptionStackEmpty;//出栈
}