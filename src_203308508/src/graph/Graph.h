/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EStatus;

template <typename Tv, typename Te> //�������͡�������
class Graph { //ͼGraphģ����
private:
   void reset() { //���ж��㡢�ߵĸ�����Ϣ��λ
      for (int i = 0; i < n; i++) { //����
         status(i) = UNDISCOVERED;
         dTime(i) = fTime(i) = -1; parent(i) = -1; priority(i) = INT_MAX;
         for (int j = 0; j < n; j++) //��
            if (exists(i,j)) status(i, j) = UNDETERMINED;
      }
   }
   void BFS(int, int&); //�����������
   void DFS(int, int&); //�����������
   void BCC(int, int&, Stack<int>&); //����DFS��˫��ͨ�����ֽ��㷨
   bool TSort(int, int&, Stack<Tv>*); //����DFS�����������㷨
public:
// ����
   int n; //������������Ŵ�0��n-1��
   virtual int insert(Tv const &) = 0; //���붥�㣬���ر��
   virtual Tv remove(int) = 0; //ɾ�����㼰������ߣ����ظö�����Ϣ
   virtual Tv& vertex(int) = 0; //����v�����ݣ��ö����ȷ���ڣ�
   virtual int inDegree(int) = 0; //����v����ȣ��ö����ȷ���ڣ�
   virtual int outDegree(int) = 0; //����v�ĳ��ȣ��ö����ȷ���ڣ�
   virtual int firstNbr(int) = 0; //����v���׸��ڽӶ���
   virtual int nextNbr(int, int) = 0; //����v�ģ�����ڶ���j�ģ���һ�ڽӶ���
   virtual VStatus& status(int) = 0; //����v��״̬
   virtual int& dTime(int) = 0; //����v��ʱ���ǩdTime
   virtual int& fTime(int) = 0; //����v��ʱ���ǩfTime
   virtual int& parent(int) = 0; //����v�ڱ������еĸ���
   virtual int& priority(int) = 0; //����v�ڱ������е����ȼ���
// ��
   int e; //������
   virtual bool exists(int, int) = 0; //��(v, u)�Ƿ����
   virtual void insert(Te const &, int, int, int) = 0; //�ڶ���v��u֮�����Ȩ��Ϊw�ı�e
   virtual Te remove(int, int) = 0; //ɾ������v��u֮��ı�e�����ظñ���Ϣ
   virtual EStatus& status(int, int) = 0; //��(v, u)��״̬
   virtual Te& edge(int, int) = 0; //��(v, u)�����ݣ��ñߵ�ȷ���ڣ�
   virtual int& weight(int, int) = 0; //��(v, u)��Ȩ��
// �㷨
   void bfs(int); //�����������
   void dfs(int); //�����������
   void bcc(int); //����DFS��˫��ͨ�����ֽ�
   Stack<Tv>* tSort(int); //����DFS����������
   void prim(int); //��С֧����Prim�㷨
   void dijkstra(int); //���·��Dijkstra�㷨
   template <typename PU> //���ȼ�����������������
   void pfs(int, PU); //���ȼ�����
};

#include "Graph_implementation.h"