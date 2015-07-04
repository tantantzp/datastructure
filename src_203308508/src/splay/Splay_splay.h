/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename NodePosi> inline //�ڽڵ�*p��*lc������Ϊ�գ�֮�佨���������ӹ�ϵ
void attachAsLChild(NodePosi p, NodePosi lc) { p->lChild = lc; if (lc) lc->parent = p; }

template <typename NodePosi> inline //�ڽڵ�*p��*rc������Ϊ�գ�֮�佨�������ң��ӹ�ϵ
void attachAsRChild(NodePosi p, NodePosi rc) { p->rChild = rc; if (rc) rc->parent = p; }

template <typename T> //Splay����չ�㷨���ӽڵ�v���������չ
BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v) { //vΪ��������ʶ�����չ�Ľڵ�λ��
   if (!v) return NULL;
   BinNodePosi(T) p; BinNodePosi(T) g; //*v�ĸ������游
   while ((p = v->parent) && (g = p->parent)) { //���¶��ϣ�������*v��˫����չ
      BinNodePosi(T) gg = g->parent; //ÿ��֮��*v����ԭ���游��great-grand parent��Ϊ��
      if (IsLChild(*v))
         if (IsLChild(*p)) { //zig-zig
            /*DSA*/printf("\tzIg-zIg :"); print(g); print(p); print(v); printf("\n");
            attachAsLChild(g, p->rChild); attachAsLChild(p, v->rChild);
            attachAsRChild(p, g); attachAsRChild(v, p);
         } else { //zig-zag
            /*DSA*/printf("\tzIg-zAg :"); print(g); print(p); print(v); printf("\n");
            attachAsLChild(p, v->rChild); attachAsRChild(g, v->lChild);
            attachAsLChild(v, g); attachAsRChild(v, p);
         }
      else
         if (IsRChild(*p)) { //zag-zag
            /*DSA*/printf("\tzAg-zAg :"); print(g); print(p); print(v); printf("\n");
            attachAsRChild(g, p->lChild); attachAsRChild(p, v->lChild);
            attachAsLChild(p, g); attachAsLChild(v, p);
         } else { //zag-zig
            /*DSA*/printf("\tzAg-zIg :"); print(g); print(p); print(v); printf("\n");
            attachAsRChild(p, v->lChild); attachAsLChild(g, v->rChild);
            attachAsRChild(v, g); attachAsLChild(v, p);
         }
      if (!gg) v->parent = NULL; //��*vԭ�ȵ����游*gg�����ڣ���*v����ӦΪ����
      else //����*gg�˺�Ӧ����*v��Ϊ����Һ���
         (g == gg->lChild) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
      updateHeight(g); updateHeight(p); updateHeight(v);
   } //˫����չ����ʱ������g == NULL����p���ܷǿ�
   if (p = v->parent) { //��p����ǿգ����������һ�ε���
      /*DSA*/if (IsLChild(*v)) { printf("\tzIg :"); print(p); print(v); printf("\n"); }
      /*DSA*/else              { printf("\tzAg :"); print(p); print(v); printf("\n"); }
      if (IsLChild(*v)) { attachAsLChild(p, v->rChild); attachAsRChild(v, p); }
      else              { attachAsRChild(p, v->lChild); attachAsLChild(v, p); }
      updateHeight(p); updateHeight(v);
   }
   v->parent = NULL; return v;
} //����֮��������ӦΪ����չ�Ľڵ㣬�ʷ��ظýڵ��λ���Ա��ϲ㺯����������