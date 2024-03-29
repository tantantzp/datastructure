/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 ******************************************************************************************/
template <typename T> BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v) { //v为非空的孙辈节点
   /*DSA*/if (!v) { printf("\a\nFail to rotate a null node\n"); exit(-1); }
   BinNodePosi(T) p = v->parent; BinNodePosi(T) g = p->parent; //视v、p和g相对位置分四种情况
   if (IsLChild(*p)) /* zig */ 
      if (IsLChild(*v)) { /* zig-zig */ //*DSA*/printf("\tzIg-zIg: ");
         p->parent = g->parent; //向上联接
         return connect34(v, p, g, v->lChild,v->rChild, p->rChild, g->rChild);
      } else { /* zig-zag */  //*DSA*/printf("\tzIg-zAg: ");
         v->parent = g->parent; //向上联接
         return connect34(p, v, g, p->lChild, v->lChild,v->rChild, g->rChild);
      }
   else  /* zag */ 
      if (IsRChild(*v)) { /* zag-zag */  //*DSA*/printf("\tzAg-zAg: ");
         p->parent = g->parent; //向上联接
         return connect34(g, p, v, g->lChild, p->lChild, v->lChild,v->rChild);
      } else { /* zag-zig */  //*DSA*/printf("\tzAg-zIg: ");
         v->parent = g->parent; //向上联接
         return connect34(g, v, p, g->lChild, v->lChild,v->rChild, p->rChild);
      }
}