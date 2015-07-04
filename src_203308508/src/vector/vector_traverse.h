/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::traverse(void (*visit)(T &)) //���ú���ָ����Ƶı���
{ for (int i = 0; i < _size; i++) visit(_elem[i]); }

template <typename T> template <typename VST> //Ԫ�����͡�������
void Vector<T>::traverse(VST & visit) //���ú���������Ƶı���
{ for (int i = 0; i < _size; i++) visit(_elem[i]); }
