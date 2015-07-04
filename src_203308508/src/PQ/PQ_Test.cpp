/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of PQ_ComplHeap & PQ_LeftHeap
 ******************************************************************************************/
#include "PQ_test.h"

/******************************************************************************************
 * ��Ի����б������Լ���ʽ��ʵ�ֵ����ȼ����У�������ͳһ�Ĳ���
 ******************************************************************************************/
template <typename H, typename T> //�����͡���������
void  testHeap(int n) {
   T* elem = new T[n/3]; //��������Ϊn/3�����飬��
   for (int i = 0; i < n/3; i++) elem[i] = dice((T)3*n); //�������������n/3������
   /*DSA*/printf("%d random keys created:\n", n/3);
   /*DSA*/for (int i = 0; i < n/3; i++) print(elem[i]); printf("\n");

   H heap = H(elem, n/3); //�������ѣ�PQ_ComplHeapʵ����Robert Floyd�㷨��
   delete [] elem;
   /*DSA*/print(heap);
   while (heap.size() < n) { //�������
      if (dice(100) < 70) { //70%���ʲ����´���
         T e = dice((T)3*n);     /*DSA*/printf("Inserting"); print(e); printf(" ...\n");
         heap.insert(e);        /*DSA*/printf("Insertion done with"); print(heap.getMax()); printf("\n");
      } else { //30%����ժ��������
         if (!heap.empty()) {   /*DSA*/printf("Deleting max ...\n");
            T e = heap.delMax();/*DSA*/printf("Deletion done with"); print(e); printf("\n");
         }
      }
      /*DSA*/print(heap);
   }
   while (!heap.empty()) { //���
      T e = heap.delMax();/*DSA*/printf("Deletion done with"); print(e); printf("\n");
      /*DSA*/print(heap);
   }
}

/******************************************************************************************
 * ���ȼ����в���
 ******************************************************************************************/
int main(int argc, char* argv[]) {
   if (2 > argc) { printf("Usage: %s <size of test>\a\a\n", argv[0]); return 1; }
   srand((unsigned int)time(NULL));

#if defined(DSA_PQ_LEFTHEAP)
   testHeap<PQ_LeftHeap<int>, int>(atoi(argv[1])); //�������͡��Ƚ�����������������ѡ��
#elif defined(DSA_PQ_COMPLHEAP)
   testHeap<PQ_ComplHeap<int>, int>(atoi(argv[1])); //�������͡��Ƚ�����������������ѡ��
#elif defined(DSA_PQ_LIST)
   testHeap<PQ_List<int>, int>(atoi(argv[1])); //�������͡��Ƚ�����������������ѡ��
#else
   printf("PQ type not defined yet\n");
#endif

   return 0;
}
