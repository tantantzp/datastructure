/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#include "binTree_test.h"

int testID = 0; //���Ա��

// ������������߶�Ϊh�Ķ�����
template <typename T> bool randomBinTree(BinTree<T>* bt, BinNodePosi(T) x, int h) {
   if (0 >= h) return false; //����h��
   if (0 < dice(h)) //��1/h�ĸ�����ֹ��ǰ��֧������
      randomBinTree(bt, bt->insertAsLC(x, dice((T)h*h*h)), h-1);
   if (0 < dice(h)) //��1/h�ĸ�����ֹ��ǰ��֧������
      randomBinTree(bt, bt->insertAsRC(x, dice((T)h*h*h)), h-1);
   return true;
}

// �ڶ����������ȷ��һ���ڵ�λ��
template <typename T> BinNodePosi(T) & randomPosiInBinTree(BinNodePosi(T) & root) {
   if (!HasChild(*root)) return root;
   if (!HasLChild(*root))
      return dice(6) ? randomPosiInBinTree(root->rChild) : root;
   if (!HasRChild(*root))
      return dice(6) ? randomPosiInBinTree(root->lChild) : root;
   return dice(2) ?
      randomPosiInBinTree(root->lChild) :
      randomPosiInBinTree(root->rChild) ;
}

template <typename T> void   testBinTree(int h) { //���Զ�����
   printf("\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++, h);
   BinTree<T>* bt = new BinTree<T>; print(bt);
   bt->insertAsRoot(dice((T)h*h*h)); print(bt);
   randomBinTree<T>(bt, bt->root(), h); print(bt);

   printf("\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++);
   bt->travPre(Double<T>()); bt->travPre(Increase<T>()); print(bt);
   bt->travIn(Double<T>()); bt->travIn(Increase<T>()); print(bt);
   bt->travPost(Double<T>()); bt->travPost(Increase<T>()); print(bt);
   bt->travLevel(Double<T>()); bt->travLevel(Increase<T>()); print(bt);
   Hailstone<T> he; bt->travIn(he); print(bt);

   printf("\n  ==== Test %2d. Remove/release subtrees in the Tree\n", testID++);
   while (!bt->empty()) {
      BinNodePosi(T)& p = randomPosiInBinTree(bt->root()); //���ѡ��һ���ڵ�
      if (dice(2)) {
         printf("removing "); print(p->data); printf(" ...\n");
         printf("%d node(s) removed\n", bt->remove(p)); print(bt);
      } else {
         printf("releasing "); print(p->data); printf(" ...\n");
         BinTree<T>* S = bt->secede(p); print(S);
         printf("%d node(s) released\n", S->size()); release(S); print(bt);
      }
   }
}

int main(int argc, char* argv[]) { //���Զ�����
   if (2 > argc) { printf("Usage: %s <size of test>\a\a\n", argv[0]); return 1; }
   srand((unsigned int)time(NULL));
   testBinTree<int>(atoi(argv[1])); //Ԫ�����͡��Ƚ�����������������ѡ��

   return 0;
}