/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of Graph
 ******************************************************************************************/
#include "Graph_test.h"

/******************************************************************************************
 * ������v�����㡢e���߹��ɵ����ͼ
 ******************************************************************************************/
template <typename Tv, typename Te> //�������͡�������
GraphMatrix<Tv, Te>* randomGraph(int n, int e) { //assert: 0 < e(e-1) <= v
   GraphMatrix<char, int>* g = new GraphMatrix<char, int>;
   while ((g->n < n) || (g->e < e)) { //�������
      if (g->n < n) //���붥��
         if (dice(100) < 65) { //65%���ʲ��붥��
            Tv vertex = (Tv) ('A'+dice(26));      /*DSA*/printf("Inserting vertex"); print(vertex); printf(" ...");
            g->insert(vertex);               /*DSA*/printf("done\n");
         } else { //35%����ɾ������
            if (1 > g->n) continue;
            int i = dice(g->n);       /*DSA*/printf("Deleting vertex %d ...", i);
            Tv v = g->remove(i);        /*DSA*/printf("done with"); print(v); printf("\n");
         }
      if ((1 < g->n) && (g->e < e)) //�����
         if (dice(100) < 65) { //65%���ʲ����
            int i = dice(g->n), j = dice(g->n); Te e = dice((Te)3*n);
                                       /*DSA*/printf("Inserting edge (%d, %d) = ", i, j); print(e); printf(" ...");
            if (g->exists(i, j)) {      /*DSA*/printf("already exists\n");
            } else {
               g->insert(e, e, i, j);      /*DSA*/printf("done\n");
            }
         } else { //35%����ɾ����
            int i = dice(g->n), j = dice(g->n);
                                       /*DSA*/printf("Deleting edge (%d, %d) ...", i, j);
            if (g->exists(i, j)) {
               Te e = g->remove(i, j);  /*DSA*/printf("done with"); print(e); printf("\n");
            } else {                   /*DSA*/printf("not exists\n");
            }
         }
   }
   for (int i = 0; i < n; i++) g->vertex(i) = 'A' + i;
   /*DSA*/print(g);
   return g;
}

/******************************************************************************************
 * �������У��ļ��ض����е���ͼ
 ******************************************************************************************/
GraphMatrix<char, int>* importGraph() {
   GraphMatrix<char, int>* g = new GraphMatrix<char, int>;
   int n; scanf("%d", &n);
   for (int i = 0; i < n; i++) { //����v������
      char vertex; scanf("%c", &vertex);  /*DSA*/printf("Inserting vertex"); print(vertex); printf(" ...");
      g->insert(vertex);                  /*DSA*/printf("done\n"); print(g);
   }
   for (int i = 0; i < n; i++)
   for (int j = 0; j < n; j++) { //�����
      int edge; scanf("%d", &edge);
      if (0 > edge) continue;             /*DSA*/printf("Inserting edge (%d, %d) = ", i, j); print(edge); printf(" ...");
      g->insert(edge, edge, i, j);        /*DSA*/printf("done\n");
   }
   return g;
}

/******************************************************************************************
 * ͼ�ṹ��ͳһ����
 ******************************************************************************************/
int main(int argc, char* argv[]) {
   if (2 > argc) { printf("Usage: %s -random <n> <e> | -import <n> <e> < <path>\a\a\n", argv[0]); return -1; }
      // -import < ..\..\_input\graph.prim.0009+0028.txt  ..\..\_output\Graph_Matrix\graph.prim.0009+0028.txt
      // -random 13 29 > ..\..\_output\Graph_Matrix\graph.random.0013+0029.001.txt
      // -random 57 219 > ..\..\_output\Graph_Matrix\graph.random.0057+0219.001.txt
   srand((unsigned int)time(NULL));
   GraphMatrix<char, int>* g;
   if (!strcmp("-random", argv[1]))
      g = randomGraph<char, int>(atoi(argv[2]),atoi(argv[3])); //�������ַ���ţ���Ϊ����Ȩ��
   else if (!strcmp("-import", argv[1]))
      g = importGraph(); //�������У��ļ��ض����е���ͼ
   else return -1;
   /*DSA*/printf("\n"); print(g);

   /*DSA*/printf("=== BFS\n");
   g->bfs(0); /*DSA*/print(g);

   /*DSA*/printf("=== DFS\n");
   g->dfs(0); /*DSA*/print(g);

   /*DSA*/printf("=== TopoSort\n");
   Stack<char>* ts = g->tSort(0); /*DSA*/ print(ts); print(g); release(ts);

   /*DSA*/printf("=== BCC\n");
   g->bcc(0); /*DSA*/print(g);

   /*DSA*/printf("=== Prim\n");
   g->prim(0); /*DSA*/print(g);
   /*DSA*/printf("=== Prim (PFS)\n");
   g->pfs(0, PrimPU<char, int>()); /*DSA*/print(g);

   /*DSA*/printf("=== Dijkstra\n");
   g->dijkstra(0); /*DSA*/print(g);
   /*DSA*/printf("=== Dijkstra (PFS)\n");
   g->pfs(0, DijkstraPU<char, int>()); /*DSA*/print(g);

   delete g; return 0;
}