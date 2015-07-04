/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const & V ) { //重载赋值操作符
   if (_elem) delete [] _elem; //释放原有内容
   copyFrom(V._elem, 0, V.size()); //整体复制
   return *this; //返回当前对象的引用，以便链式赋值
}