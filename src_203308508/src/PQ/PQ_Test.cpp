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
 * 针对基于列表、向量以及左式堆实现的优先级队列，做过程统一的测试
 ******************************************************************************************/
template <typename H, typename T> //堆类型、词条类型
void  testHeap(int n) {
   T* elem = new T[n/3]; //创建容量为n/3的数组，并
   for (int i = 0; i < n/3; i++) elem[i] = dice((T)3*n); //在其中随机生成n/3个词条
   /*DSA*/printf("%d random keys created:\n", n/3);
   /*DSA*/for (int i = 0; i < n/3; i++) print(elem[i]); printf("\n");

   H heap = H(elem, n/3); //批量建堆（PQ_ComplHeap实现了Robert Floyd算法）
   delete [] elem;
   /*DSA*/print(heap);
   while (heap.size() < n) { //随机测试
      if (dice(100) < 70) { //70%概率插入新词条
         T e = dice((T)3*n);     /*DSA*/printf("Inserting"); print(e); printf(" ...\n");
         heap.insert(e);        /*DSA*/printf("Insertion done with"); print(heap.getMax()); printf("\n");
      } else { //30%概率摘除最大词条
         if (!heap.empty()) {   /*DSA*/printf("Deleting max ...\n");
            T e = heap.delMax();/*DSA*/printf("Deletion done with"); print(e); printf("\n");
         }
      }
      /*DSA*/print(heap);
   }
   while (!heap.empty()) { //清空
      T e = heap.delMax();/*DSA*/printf("Deletion done with"); print(e); printf("\n");
      /*DSA*/print(heap);
   }
}

/******************************************************************************************
 * 优先级队列测试
 ******************************************************************************************/
int main(int argc, char* argv[]) {
   if (2 > argc) { printf("Usage: %s <size of test>\a\a\n", argv[0]); return 1; }
   srand((unsigned int)time(NULL));

#if defined(DSA_PQ_LEFTHEAP)
   testHeap<PQ_LeftHeap<int>, int>(atoi(argv[1])); //词条类型、比较器可以在这里任意选择
#elif defined(DSA_PQ_COMPLHEAP)
   testHeap<PQ_ComplHeap<int>, int>(atoi(argv[1])); //词条类型、比较器可以在这里任意选择
#elif defined(DSA_PQ_LIST)
   testHeap<PQ_List<int>, int>(atoi(argv[1])); //词条类型、比较器可以在这里任意选择
#else
   printf("PQ type not defined yet\n");
#endif

   return 0;
}
