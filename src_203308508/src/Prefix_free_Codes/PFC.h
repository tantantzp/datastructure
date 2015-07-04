/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "../_share/util.h"
/*DSA*/#include "../UniPrint/print.h"

/******************************************************************************************
 * PFC����ʹ�õ����ݽṹ
 ******************************************************************************************/
#include "../BinTree/BinTree.h" //��BinTreeʵ��PFC��
typedef BinTree<char> PFCTree; //PFC��

#include "../Vector/Vector.h" //��Vectorʵ��PFCɭ��
typedef Vector<PFCTree*> PFCForest; //PFCɭ��

#include "../Bitmap/Bitmap.h" //ʹ��λͼ��ʾ�����Ʊ���
#include "../Skiplist/Skiplist.h" //ʹ����ת���ʾ�����(�ַ������봮��
typedef Skiplist<char, char*> PFCTable; //PFC�����

#define  N_CHAR  (0x80 - 0x20) //ֻ���ǿɴ�ӡ�ַ�
