/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST�ڵ���ת�任ͳһ�㷨��3�ڵ� + 4�����������ص���֮��ֲ��������ڵ��λ��
 * ע�⣺��������������ȷָ���ϲ�ڵ㣨������ڣ�������������������ϲ㺯�����
 ******************************************************************************************/
template <typename T> BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v) { //vΪ�ǿյ��ﱲ�ڵ�
   /*DSA*/if (!v) { printf("\a\nFail to rotate a null node\n"); exit(-1); }
   BinNodePosi(T) p = v->parent; BinNodePosi(T) g = p->parent; //��v��p��g���λ�÷��������
   if (IsLChild(*p)) /* zig */ 
      if (IsLChild(*v)) { /* zig-zig */ //*DSA*/printf("\tzIg-zIg: ");
         p->parent = g->parent; //��������
         return connect34(v, p, g, v->lChild,v->rChild, p->rChild, g->rChild);
      } else { /* zig-zag */  //*DSA*/printf("\tzIg-zAg: ");
         v->parent = g->parent; //��������
         return connect34(p, v, g, p->lChild, v->lChild,v->rChild, g->rChild);
      }
   else  /* zag */ 
      if (IsRChild(*v)) { /* zag-zag */  //*DSA*/printf("\tzAg-zAg: ");
         p->parent = g->parent; //��������
         return connect34(g, p, v, g->lChild, p->lChild, v->lChild,v->rChild);
      } else { /* zag-zig */  //*DSA*/printf("\tzAg-zIg: ");
         v->parent = g->parent; //��������
         return connect34(g, v, p, g->lChild, v->lChild,v->rChild, p->rChild);
      }
}